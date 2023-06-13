#include <iostream>
#include "Buyer.h"

namespace STD {
	Buyer::Buyer() {
		setName((char*)"no name");
		setPassword((char*)"no password");
		setAge(0);
		//std::cout << "[Log] Empty Buyer created" << std::endl;
		m_GoodsCount = 0;
	}

	Buyer::Buyer(char name[], char password[], int age) {
		setName(name);
		setPassword(password);
		setAge(age);
		cart.setGoodsList(nullptr);
		m_GoodsCount = 0;
	}

	Buyer::Buyer(char name[], char password[], int age, Goods* goodslist, int goodscount) {
		setName(name);
		setPassword(password);
		setAge(age);
		m_GoodsCount = goodscount;
		m_GoodsList = goodslist;
		cart.setGoodsList(m_GoodsList);
		cart.setGoodsCountAll(m_GoodsCount);
	};

	Buyer::Buyer(Goods* goodslist, int goodscount) {
		m_GoodsCount = goodscount;
		m_GoodsList = goodslist;
		cart.setGoodsList(m_GoodsList);
		cart.setGoodsCountAll(m_GoodsCount);
	};

	Buyer::~Buyer() {
		
	}

	Goods* Buyer::getGoodsList()
	{
		return m_GoodsList;
	}

	void Buyer::showGoodsList()
	{
		std::cout << "Goods list of User " << getName() << std::endl;

		for (int i = 0; i < m_GoodsCount; i++)
		{
			std::cout << "Name: " << m_GoodsList[i].getGoodsName() << std::endl;
		}
	}

	void Buyer::sortGoods(int sortName)
	{
		Goods* tmpGoods = new Goods();

		for (int i = 0; i < m_GoodsCount; i++)
		{
			std::cout << m_GoodsList[i].getGoodsName() << std::endl;
		}
		std::cout << std::endl;

		if (sortName == 0) {

			for (int i = 0; i < m_GoodsCount; i++)
			{
				for (int j = 0; j < m_GoodsCount - 1; j++)
				{
					if (strcmp(m_GoodsList[j].getGoodsName(), m_GoodsList[j + 1].getGoodsName()) > 0)
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
			if (sortName == 1) {

				for (int i = 0; i < m_GoodsCount; i++)
				{
					for (int j = 0; j < m_GoodsCount - 1; j++)
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

					for (int i = 0; i < m_GoodsCount; i++)
					{
						for (int j = 0; j < m_GoodsCount - 1; j++)
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

						for (int i = 0; i < m_GoodsCount; i++)
						{
							for (int j = 0; j < m_GoodsCount - 1; j++)
							{
								if (m_GoodsList[j].getGoodsWeight()>m_GoodsList[j + 1].getGoodsWeight())
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
						std::cout << "Something wrong!" << std::endl;
					}


		for (int i = 0; i < m_GoodsCount; i++)
		{
			std::cout << m_GoodsList[i].getGoodsName() << i << std::endl;
		}
		std::cout << std::endl;

	}

	void Buyer::addNewGoods(char GoodsName[], char GoodsCompanySeller[], char GoodsDescription[], int GoodsWeight) {
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

	void Buyer::setGoodsList(Goods* goods) {
		m_GoodsList = goods;
	};
	
	void  Buyer::setGoodsCount(int count) {
		m_GoodsCount = count;
	};

	void Buyer::setGoodsList(Goods* list, int count)
	{
		m_GoodsCount = count;
		m_GoodsList = new Goods[m_GoodsCount];
		for (int i = 0; i < m_GoodsCount; i++)
		{
			m_GoodsList[i] = list[i];
		}
	}

	int Buyer::getGoodsCount()
	{
		return m_GoodsCount;
	}



}