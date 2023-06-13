#include <iostream>
#include "Data.h"

namespace STD {

	const char* strSortName[4]
	{
		"Name",
		"CompanySeller",
		"Description",
		"Weight"
	};

	void Data::GenerateId(int key) {
		srand(time(0));
		id = rand() * 100;
		srand(time(0));
		id = (id / rand()) + key;
	}

	void Data::SetCurrentTime() {
		time_t t = time(NULL);
		struct tm tm;
		localtime_s(&tm, &t);
		CurTime.Day = tm.tm_mday;
		CurTime.Mounth = tm.tm_mon + 1;
		CurTime.Year = tm.tm_year + 1900;
		CurTime.Hours = tm.tm_hour;
		CurTime.Minutes = tm.tm_min;
		CurTime.Seconds = tm.tm_sec;
	}

	Date Data::GetId() {
		return id;
	}

	Str Data::GetDateOfCreation() {
		return DateOfCreation;
	}

	Data::Data() {
		SetCurrentTime();
		GenerateId(CurTime.Seconds);
		//std::cout << "Creating Item: " << std::endl;
		//std::cout << "ID: " <<this->GetId()<< std::endl;
		//std::cout << "Date of creation: ";
		//ShowCurrentTime();
	}

	Data::~Data() {
	
	}

	void Data::ShowCurrentTime()
	{
		std::cout << CurTime.Day << "." << CurTime.Mounth << "." << CurTime.Year << "   " << CurTime.Hours << ":" << CurTime.Minutes << ":" << CurTime.Seconds << std::endl;
	}

}