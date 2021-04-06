#pragma once

#include <string>
#include <list>
#include <iostream>

#include "SeatingChart.h"

class Show {
private:
	void AllocateSeatingChart() {
		seatingChart = new SeatingChart ();
	}

	void DeleteSeatingChart() {
		delete seatingChart;
	}

public:
	int Id;
	std::string Name;
	std::string Date;
	std::string Time;
	std::string Description;
	SeatingChart* seatingChart;
	Show(int id, std::string name, std::string date, std::string time, std::string description) {
		Id = id;
		Name = name;
		Date = date;
		Time = time;
		Description = description;
	};

	std::list<Seat> ViewAvailableSeats() {
		std::list<Seat> AvailableSeats = seatingChart.SeeAvailableSeats();
		return AvailableSeats;
	};

	void Edit(Show show) {
		//Mock database call
		sql::Statement->execute("UPDATE show SET name = " + show.Name + " date = " + show.Date + " time = " + show.Time + " description = " + show.Description + " where ID = " + Id);
	}

	void Delete(Show show) {
		//Mock database call
		sql::Statement->execute("DELETE FROM show WHERE ID = " Id);
		DeleteSeatingChart();
	}

	void Create(Show show) {
		//Mock database call
		sql::Statement->execute("INSERT INTO show (ID, name, date, time, description) VALUES ( " + show.Id, show.Name, show.Date, show.Time, show.Description + " )");
		AllocateSeatingChart();
	}
};