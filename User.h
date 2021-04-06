#pragma once

#include <string>
#include <list>
#include <iostream>

#include "Show.h"

class User {
protected:
	std::string FirstName;
	std::string LastName;
	std::string Address;
private:
	std::string Username;
	std::string Password;
public:
	std::list<Show> ViewUpcomingShows() {};
	int Login() {
		std::cout << "Please enter your username" << std::endl;
		std::cin >> Username;
		std::cout << "Please senter your password" << std::endl;
		std::cin >> Password;

		try {
			//Mock database call
			sql::Statement->execute("SELECT * FROM users WHERE username = " + Username);
			return 403;
		}
		catch (int myErr) {
			std::cout << "Access denied - incorrect username and password combination" << std::endl;
			return 200;
		}
	};
};