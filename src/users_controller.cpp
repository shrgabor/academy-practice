#include "users_controller.h"
#include <iostream>
#include <json.hpp>

using namespace nlohmann;

#define LOG(str) std::cout << str << std::endl

std::vector<std::string> UsersController::users;

void UsersController::getAll(const Request &request, Response &response)
{
	// TODO iterate users and dump json
	response.set_content("All the users!", "text/plain");
}
void UsersController::getById(const Request &request, Response &response)
{
	auto id = request.matches[1].str();
	// TODO find in users and return as json
	response.set_content(id, "text/plain");
}

void UsersController::set(const Request &request, Response &response)
{
	try {
		LOG(request.body);
		json reqBody = json::parse(request.body);

		users.emplace_back(reqBody.at("name"));

		json resBody = {
			{"id", users.size()},
		};

		response.set_content(resBody.dump(), "application/json");
	} catch (...) {
		// TODO respond with error code
//		response.set_content(, "application/json");
	}
}

void UsersController::deleteById(const Request &request, Response &response)
{

}

void UsersController::modifyById(const Request &request, Response &response)
{

}
