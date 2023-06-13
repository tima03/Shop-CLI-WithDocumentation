#pragma once
#include "Data.h"

namespace STD {
	class Human : public Data {
	
	public:
		Human();
		~Human();

		void setName(char name[]);
		void setPassword(char password[]);
		void setAge(int age);

		char* getName();
		char* getPassword();
		int getAge();
		
	private:
		char m_name[20];
		char m_password[20];
		int m_age;

	};
}