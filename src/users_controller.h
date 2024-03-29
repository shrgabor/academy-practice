#pragma once

#include <httplib.h>
#include <string>
#include <map>

using namespace httplib;

class UsersController
{
public:
	static void getAll(const Request &req, Response &res);
	static void getById(const Request &request, Response &response);
	static void set(const Request &request, Response &response);

private:
	static std::map<unsigned long, std::string> users;
	static std::mutex reqMutex;
	static unsigned long nextId;
};
