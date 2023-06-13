#include "Human.h"
#include <string.h>

namespace STD {
	
	Human::Human()
	{
		m_age = 0;
		strcpy_s(m_password, "No Password");
		strcpy_s(m_name, "No Name");
	}

	Human::~Human() {
	
	}

	void Human::setName(char name[])
	{
		strcpy_s(m_name, name);
	}

	void Human::setAge(int age)
	{
		m_age;
		m_age = age;
	}

	void Human::setPassword(char password[])
	{
		strcpy_s(m_password, password);
	}

	char* Human::getName()
	{
		return m_name;
	}

	int Human::getAge()
	{
		return m_age;
	}

	char* Human::getPassword()
	{
		return m_password;
	}

}