#include <iostream>
#include "Employee.h"
#include "Goods.h"

namespace STD {
	Employee::Employee(){
		setName((char*)"no name");
		setPassword((char*)"no password");
		setAge(0);
		//std::cout << "[Log] Empty Emploee created" << std::endl;
		m_GoodsCount = 0;
	}

	Employee::Employee(char name[], char password[], int age) {
		setName(name);
		setPassword(password);
		setAge(age);
		m_GoodsCount = 0;
	}

	Employee::~Employee() {
		//if (m_GoodsList != nullptr) {
			//delete[] m_GoodsList;
		//}
	}

	void Employee::addNewGoods(char GoodsName[], char GoodsCompanySeller[], char GoodsDescription[], int GoodsWeight) {
		Goods* goods = new Goods(GoodsName, GoodsCompanySeller, GoodsDescription, GoodsWeight);
		if (m_GoodsCount != 0)
		{
			Goods* temp = new Goods[m_GoodsCount + 1];
			for (int i = 0; i < m_GoodsCount; i++)
			{
				temp[i] = m_GoodsList[i];
			}
			temp[m_GoodsCount] = *goods;
			m_GoodsList = temp;
		}
		else
		{
			m_GoodsList = new Goods[1];
			m_GoodsList[0] = *goods;
		}
		m_GoodsCount++;
	}

	void Employee::deleteGoods(int GoodsPosition) {
		bool temp1 = false;
		Goods* temp = new Goods[m_GoodsCount - 1];
		for (int i = 0; i < m_GoodsCount; i++)
		{
			if (GoodsPosition == i) { temp1 = true; }
			if (!temp1) {
				temp[i] = m_GoodsList[i];
			}
			else if (!(GoodsPosition == i)) {
				temp[i - 1] = m_GoodsList[i];
			}

		}
		delete[] m_GoodsList;
		m_GoodsList = temp;
		m_GoodsCount--;
	}

	Goods* Employee::getGoodsList()
	{
		return m_GoodsList;
	}

	void Employee::showGoodsList()
	{
		std::cout << "Goods list of User " << getName() << std::endl;

		for (int i = 0; i < m_GoodsCount; i++)
		{
			std::cout << "Name: " << m_GoodsList[i].getGoodsName() << std::endl;
		}
	}

	void Employee::setGoodsList(Goods* goods) {
		m_GoodsList = goods;
	};

	void Employee::setGoodsList(Goods* list, int count)
	{
		m_GoodsCount = count;
		m_GoodsList = new Goods[m_GoodsCount];
		for (int i = 0; i < m_GoodsCount; i++)
		{
			m_GoodsList[i] = list[i];
		}
	}

	void  Employee::setGoodsCount(int count) {
		m_GoodsCount = count;
	};

	int Employee::getGoodsCount()
	{
		return m_GoodsCount;
	}

}