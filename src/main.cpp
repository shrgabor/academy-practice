#include <httplib.h>
#include "users_controller.h"

std::string dump_headers(const Headers &headers) {
	std::string s;
	char buf[BUFSIZ];

	for (auto it = headers.begin(); it != headers.end(); ++it) {
		const auto &x = *it;
		snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
		s += buf;
	}

	return s;
}

std::string log(const Request &req, const Response &res) {
	std::string s;
	char buf[BUFSIZ];

	s += "================================\n";

	snprintf(buf, sizeof(buf), "%s %s %s", req.method.c_str(),
	         req.version.c_str(), req.path.c_str());
	s += buf;

	std::string query;
	for (auto it = req.params.begin(); it != req.params.end(); ++it) {
		const auto &x = *it;
		snprintf(buf, sizeof(buf), "%c%s=%s",
		         (it == req.params.begin()) ? '?' : '&', x.first.c_str(),
		         x.second.c_str());
		query += buf;
	}
	snprintf(buf, sizeof(buf), "%s\n", query.c_str());
	s += buf;

	s += dump_headers(req.headers);

	s += "--------------------------------\n";

	snprintf(buf, sizeof(buf), "%d %s\n", res.status, res.version.c_str());
	s += buf;
	s += dump_headers(res.headers);
	s += "\n";

	if (!res.body.empty()) { s += res.body; }

	s += "\n";

	return s;
}

int main()
{
	using namespace httplib;

	Server server;

	server.Get("/", [](const Request &req, Response &res) {});
	server.Get(R"(/users)", UsersController::getAll);
	server.Get(R"(/users/(\d+))", UsersController::getById);
	server.Post(R"(/users)", UsersController::set);
	server.Delete(R"(/users/(\d+))", UsersController::deleteById);
	server.Put(R"(/users/(\d+))", UsersController::modifyById);

	server.set_logger([](const Request &req, const Response &res) {
		printf("%s", log(req, res).c_str());
	});

	server.listen("localhost", 3000);
}
