#include "users_controller.h"
#include <iostream>
#include <json.hpp>

using namespace nlohmann;

std::vector<std::string> UsersController::users;
std::mutex UsersController::reqMutex;

void UsersController::getAll(const Request &request, Response &response)
{
	std::lock_guard<std::mutex> lock(reqMutex);
	/**
	 * [
	 *   {name: "Izé Hozé"},
	 *   {name: "Izé Hozé"}
	 * ]
	 */
	json resBody = json::array({});

	for (const std::string& name : users) {
		resBody.push_back({{"name", name}});
	}

	response.set_content(resBody.dump(), "application/json");
}

void UsersController::getById(const Request &request, Response &response)
{
	std::lock_guard<std::mutex> lock(reqMutex);
	auto reqId = request.matches[1].str();

	unsigned long id = 0;
	std::string name;

	try {
		id = std::stoul(reqId); // NOTE: this could throw an exception
		name = users.at(id); // NOTE: this could throw an exception

		/**
		 * {name: "Izé Hozé"}
		 */
		json resBody = {
			{"name", name},
		};

		response.set_content(resBody.dump(), "application/json");
	} catch (...) {
		if (users.size() <= id) {
			response.status = 404;
		} else {
			response.status = 400;
		}
	}
}

void UsersController::set(const Request &request, Response &response)
{
	std::lock_guard<std::mutex> lock(reqMutex);
	try {
		std::cout << request.body << std::endl;

		json reqBody = json::parse(request.body); // NOTE: this could throw an exception

		users.emplace_back(reqBody.at("name")); // NOTE: this could throw an exception

		/**
		 * {id: 1}
		 */
		json resBody = {
			{"id", users.size()-1},
		};

		response.set_content(resBody.dump(), "application/json");
	} catch (...) {
		response.status = 400;
	}
}
