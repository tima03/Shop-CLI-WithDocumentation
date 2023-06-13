#include <iostream>
#include "App.h"

namespace STD
{
	App::App(Buyer* buyer, Goods* goods, Employee* employee)
	{
		//m_usersCount =  new int (sizeof(users) / sizeof(users[0]));
		m_buyerCount = 0;
		m_goodsCount = 0;
		m_employeeCount = 0;
		m_BuyerList = new Buyer[m_buyerCount];
		m_GoodsList = new Goods[m_goodsCount];
		m_EmployeeList = new Employee[m_employeeCount];

		if (m_buyerCount>0) {
			for (int i = 0; i < m_buyerCount; i++)
			{
				m_BuyerList[i] = buyer[i];
			}
		}

		if (m_goodsCount>0) {
			for (int i = 0; i < m_goodsCount; i++)
			{
				m_GoodsList[i] = goods[i];
			}
		}

		if (m_employeeCount > 0) {
			for (int i = 0; i < m_employeeCount; i++)
			{
				m_EmployeeList[i] = employee[i];
			}
		}

	}

	App::~App()
	{
		//delete[] m_BuyerList;
		//delete[] m_GoodsList;
		//delete[] m_EmployeeList;
	}

	Buyer* App::filterBuyer()
	{
		int* tmpCounter = new int(0);
		// Получаем число совершеннолетних
		std::cout << "Common Buyer List: " << std::endl;
		for (int i = 0; i < m_buyerCount; i++)
		{
			std::cout << m_BuyerList[i].getName() << std::endl;
			if (m_BuyerList[i].getAge() >= 18)
			{
				(*tmpCounter)++;
			}
		}
		std::cout << std::endl;
		std::cout << "Filtered Buyer List: " << std::endl;
		Buyer* newList = new Buyer[*tmpCounter];
		for (int i = 0; i < m_buyerCount; i++)
		{
			if (m_BuyerList[i].getAge() >= 18)
			{
				newList[i] = m_BuyerList[i];
				std::cout << newList[i].getName() << std::endl;
			}
		}

		delete tmpCounter;
		return newList;
	}

	template <typename T>

	T* App::filter(T* list, int count)
	{
		int tmpCounter = 0;
		for (int i = 0; i < count; i++)
		{
			if (list[i].getAge() >= 18)
			{
				(tmpCounter)++;
			}
		}
		std::cout << std::endl;
		std::cout << "Filtered List: " << std::endl;
		T* newList = new T[tmpCounter];
		for (int i = 0; i < count; i++)
		{
			if (list[i].getAge() >= 18)
			{
				newList[i] = list[i];
				std::cout << list[i].getName() << std::endl;
			}
		}
		return newList;
	}

	Employee* App::filterEmployee()
	{
		int* tmpCounter = new int(0);
		std::cout << "Common Employee List: " << std::endl;
		for (int i = 0; i < m_employeeCount; i++)
		{
			if (m_EmployeeList[i].getAge() >= 18)
			{
				(*tmpCounter)++;
			}
			std::cout << m_EmployeeList[i].getName() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Filtered Employee List: " << std::endl;
		Employee* newList = new Employee[*tmpCounter];
		for (int i = 0; i < m_employeeCount; i++)
		{
			if (m_EmployeeList[i].getAge() >= 18)
			{
				newList[i] = m_EmployeeList[i];
				std::cout << newList[i].getName() << std::endl;
			}
		}
		delete tmpCounter;
		return newList;
	}

	Goods* App::filterGoods(int goodsType)
	{
		int* tmpCounter = new int(0);
		std::cout << "Common Goods List: " << std::endl;
		for (int i = 0; i < m_goodsCount; i++)
		{
			std::cout << m_GoodsList[i].getGoodsName() << std::endl;
			//if (m_GoodsList[i].getEnumGenre() == goodsType)
			{
				*tmpCounter++;
			}
		}
		std::cout << std::endl;
		std::cout << "Filtered Goods List: " << std::endl;
		Goods* newList = new Goods[*tmpCounter];
		for (int i = 0; i < m_goodsCount; i++)
		{
			//if (m_GoodsList[i].getEnumGenre() == goodsType)
			{
				newList[i] = m_GoodsList[i];
				std::cout << newList[i].getGoodsName() << std::endl;
			}
		}

		delete tmpCounter;
		return newList;
	}

	int App::addBuyer(char* tmpName, char* tmpPassword, int* tmpAge)
	{
		Buyer* buyer = new Buyer(tmpName, tmpPassword, *tmpAge);
		if (m_buyerCount != 0)
		{
			Buyer* temp = new Buyer[m_buyerCount + 1];
			for (int i = 0; i < m_buyerCount; i++)
			{
				temp[i] = m_BuyerList[i];
			}
			temp[m_buyerCount] = *buyer;
			m_BuyerList = temp;
		}
		else
		{
			m_BuyerList = new Buyer[1];
			m_BuyerList[0] = *buyer;
		}
		m_buyerCount++;

		return 0;
	}

	void App::addGoods(Goods* newGoods)
	{
		Goods* newList = new Goods[m_goodsCount + 1];
		for (int i = 0; i < m_goodsCount; i++)
		{
			newList[i] = m_GoodsList[i];
			std::cout << newList[i].getGoodsName() << std::endl;
		}
		newList[m_goodsCount] = *newGoods;
		m_GoodsList = newList;
		m_goodsCount++;
	}

	int App::addEmployee(char* tmpName, char* tmpPassword, int* tmpAge)
	{
		// Вынести в функцию

		Employee* empl = new Employee(tmpName, tmpPassword, *tmpAge);
		if (m_employeeCount != 0)
		{
			Employee* temp = new Employee[m_employeeCount + 1];
			for (int i = 0; i < m_employeeCount; i++)
			{
				temp[i] = m_EmployeeList[i];
			}
			temp[m_employeeCount] = *empl;
			m_EmployeeList = temp;
		}
		else
		{
			m_EmployeeList = new Employee[1];
			m_EmployeeList[0] = *empl;
		}
		m_employeeCount++;

		return 0;
	}



	void App::sortGoods(int sortName)
	{
		Goods* tmpGoods = new Goods();

		for (int i = 0; i < m_goodsCount; i++)
		{
			std::cout << m_GoodsList[i].getGoodsName() << std::endl;
		}
		std::cout << std::endl;

		if (sortName == 0) {
		
			for (int i = 0; i < m_goodsCount; i++)
			{
				for (int j = 0; j < m_goodsCount-1; j++)
				{
					 if (strcmp(m_GoodsList[j].getGoodsName(),m_GoodsList[j+1].getGoodsName())>0)
						{
							*tmpGoods = m_GoodsList[j];
							m_GoodsList[j] = m_GoodsList[j+1];
							m_GoodsList[j+1] = *tmpGoods;
							break;
						}
				}
			}

		}
		else
			if (sortName == 1) {
			
				for (int i = 0; i < m_goodsCount; i++)
				{
					for (int j = 0; j < m_goodsCount - 1; j++)
					{
						if (strcmp(m_GoodsList[j].getGoodsCompanySeller(), m_GoodsList[j + 1].getGoodsCompanySeller()) > 0)
						{
							*tmpGoods = m_GoodsList[j];
							m_GoodsList[j] = m_GoodsList[j + 1];
							m_GoodsList[j + 1] = *tmpGoods;
							break;
						}
					}
				}

			}
			else
				if (sortName == 2) {
				
					for (int i = 0; i < m_goodsCount; i++)
					{
						for (int j = 0; j < m_goodsCount - 1; j++)
						{
							if (strcmp(m_GoodsList[j].getGoodsDescription(), m_GoodsList[j + 1].getGoodsDescription()) > 0)
							{
								*tmpGoods = m_GoodsList[j];
								m_GoodsList[j] = m_GoodsList[j + 1];
								m_GoodsList[j + 1] = *tmpGoods;
								break;
							}
						}
					}

				}
				else
					if (sortName == 3) {

						for (int i = 0; i < m_goodsCount; i++)
						{
							for (int j = 0; j < m_goodsCount - 1; j++)
							{
								if (m_GoodsList[j].getGoodsWeight() > m_GoodsList[j + 1].getGoodsWeight())
								{
									*tmpGoods = m_GoodsList[j];
									m_GoodsList[j] = m_GoodsList[j + 1];
									m_GoodsList[j + 1] = *tmpGoods;
									break;
								}
							}
						}

					}
					else
					{
						std::cout << "Something wrong!"<<std::endl;
					}


		for (int i = 0; i < m_goodsCount; i++)
		{
			std::cout << m_GoodsList[i].getGoodsName() << i << std::endl;
		}
		std::cout << std::endl;

	}

	void App::showGoodsList() {
		for (int i = 0; i < m_goodsCount; i++)
		{
			std::cout << "Name: " << m_GoodsList[i].getGoodsName() << std::endl;
		}
	}

	template <typename T>
	T* App::deleteItem(int index, T* list, int count)
	{
		bool temp1 = false;
		T* temp = new T[count - 1];
		for (int i = 0; i < count; i++)
		{
			if (index == i) { temp1 = true; }
			if (!temp1) {
				temp[i] = list[i];
			}
			else if (!(index == i)) {
				temp[i - 1] = list[i];
			}

		}
		delete[] list;
		list = temp;
		count--;
	}


	void App::deleteBuyer(int index)
	{
		bool temp1 = false;
		Buyer* temp = new Buyer[m_buyerCount - 1];
		for (int i = 0; i < m_buyerCount; i++)
		{
			if (index == i) { temp1 = true; }
			if (!temp1) {
				temp[i] = m_BuyerList[i];
			}
			else if (!(index == i)) {
				temp[i - 1] = m_BuyerList[i];
			}

		}
		delete[] m_BuyerList;
		m_BuyerList = temp;
		m_buyerCount--;
	}

	void App::deleteGoods(int index)
	{
		bool temp1 = false;
		Goods* temp = new Goods[m_goodsCount - 1];
		for (int i = 0; i < m_goodsCount; i++)
		{
			if (index == i) { temp1 = true; }
			if (!temp1) {
				temp[i] = m_GoodsList[i];
			}
			else if (!(index == i)) {
				temp[i - 1] = m_GoodsList[i];
			}

		}
		delete[] m_GoodsList;
		m_GoodsList = temp;
		m_goodsCount--;
	}

	void App::deleteEmployee(int index)
	{
		bool temp1 = false;
		Employee* temp = new Employee[m_employeeCount - 1];
		for (int i = 0; i < m_employeeCount; i++)
		{
			if (index == i) { temp1 = true; }
			if (!temp1) {
				temp[i] = m_EmployeeList[i];
			}
			else if (!(index == i)) {
				temp[i - 1] = m_EmployeeList[i];
			}

		}
		delete[] m_EmployeeList;
		m_EmployeeList = temp;
		m_employeeCount--;
	}

	Buyer* App::getBuyerList()
	{
		return m_BuyerList;
	}

	int App::getBuyerCount()
	{
		return m_buyerCount;
	}

	Employee* App::getEmployeeList()
	{
		return m_EmployeeList;
	}

	int App::getEmployeeCount()
	{
		return m_employeeCount;
	}

	Goods* App::getGoodsList()
	{
		return m_GoodsList;
	}

	int App::getGoodsCount()
	{
		return m_goodsCount;
	}

	void App::setBuyerList(Buyer* list, int count)
	{
		delete[] m_BuyerList;
		m_buyerCount = count;
		m_BuyerList = new Buyer[m_buyerCount];
		for (int i = 0; i < m_buyerCount; i++)
		{
			m_BuyerList[i] = list[i];
			std::cout << "[Log][Loaded Item] " << m_BuyerList[i].getName() << std::endl;
			std::cout << "[Log][Loaded Item][Loaded SubItem] " << (m_BuyerList[i].getGoodsList())->getGoodsName() << std::endl;
		}

	}

	void App::setEmployeeList(Employee* list, int count)
	{
		delete[] m_EmployeeList;
		m_employeeCount = count;
		m_EmployeeList = new Employee[m_employeeCount];
		for (int i = 0; i < m_employeeCount; i++)
		{
			m_EmployeeList[i] = list[i];
		}
	}
	void App::setGoodsList(Goods* list, int count)
	{
		delete[] m_GoodsList;
		m_goodsCount = count;
		m_GoodsList = new Goods[m_goodsCount];
		for (int i = 0; i < m_goodsCount; i++)
		{
			m_GoodsList[i] = list[i];
		}
	}

}
