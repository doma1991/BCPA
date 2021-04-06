#pragma once

#include "Show.h"
#include "User.h"

#include <string>
#include <list>
#include <iostream>

class VenueManager : public User {
private:
	std::string Venue;
public:
	void AddShow() {
		int Id = std::rand();
		std::string Name;
		std::string Date;
		std::string Time;
		std::string Description;

		std::cout << "Please enter show name." << std::endl;
		std::cin >> Name;
		std::cout << "Please enter show date." << std::endl;
		std::cin >> Date;
		std::cout << "Please enter show time." << std::endl;
		std::cin >> Time;
		std::cout << "Please enter show description." << std::endl;
		std::cin >> Description;

		Show show (Id, Name, Date, Time, Description);
		
		try {
			show.Create(show);
			std::cout << "Show added successfully." << std::endl;
		}
		catch (int myErr) {
			std::cout << "Uh-oh, something went wrong. Try again later." << std::endl;
		}

	}

	void CancelShow(Show show) {

		try {
			show.Delete(show);
			std::cout << "Show deleted successfully." << std::endl;
		}
		catch (int myErr) {
			std::cout << "Uh-oh, something went wrong. Try again later." << std::endl;
		}
	}

	void EditShow(Show show) {

		std::string Name;
		std::string Date;
		std::string Time;
		std::string Description;

		std::cout << "Please enter new show name." << std::endl;
		std::cin >> Name;
		std::cout << "Please enter new show date." << std::endl;
		std::cin >> Date;
		std::cout << "Please enter new show time." << std::endl;
		std::cin >> Time;
		std::cout << "Please enter new show description." << std::endl;
		std::cin >> Description;

		Show newShow (show.Id, Name, Date, Time, Description);

		try {
			show.Edit(newShow);
			std::cout << "Show updated successfully." << std::endl;
		}
		catch (int myErr) {
			std::cout << "Uh-oh, something went wrong. Try again later." << std::endl;
		}
	}

	std::list<Show> ViewUpcomingShows() {
		std::list<Show> ShowList;

		//Mock database call
		ShowList = sql::Statement->execute("SELECT * FROM Shows");
	
		return ShowList;
	};
};