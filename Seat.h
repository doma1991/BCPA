#pragma once

#include <string>

class Seat {
public:
	int Id;
	std::string Location;
	int Price;
	std::string Type;
	bool Assigned;
};