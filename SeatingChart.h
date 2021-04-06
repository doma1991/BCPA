#pragma once

#include <string>
#include <list>
#include <iostream>

#include "Seat.h"


class SeatingChart {
public:
	int NumberOfSeats;
	std::list<Seat> AllSeats;

	std::list<Seat> SeeAvailableSeats() {
		std::list<Seat> VacantSeats;
		std::list<Seat>::iterator it;

		for (it = AllSeats.begin(); it != AllSeats.end(); it++) {
			if (it->Assigned == false) {
				VacantSeats.push_back(*it);
			}
		}
		return VacantSeats;
	};
};