#include <string.h>
#include <iostream>
#include "Goods.h"

namespace STD {

	void Goods::setGoodsName(char name[])
	{
		strcpy_s(m_GoodsName, name);
	}

	void Goods::setGoodsCompanySeller(char companyseller[])
	{
		strcpy_s(m_GoodsCompanySeller, companyseller);
	}

	void Goods::setGoodsDescription(char discription[])
	{
		strcpy_s(m_GoodsDescription, discription);
	}

	void Goods::setGoodsWeight(int weight)
	{
		m_GoodsWeight = weight;
	}

	char* Goods::getGoodsName()
	{
		return m_GoodsName;
	}

	char* Goods::getGoodsCompanySeller()
	{
		return m_GoodsCompanySeller;
	}

	char* Goods::getGoodsDescription()
	{
		return m_GoodsDescription;
	}

	int Goods::getGoodsWeight()
	{
		return m_GoodsWeight ;
	}

	void Goods::showInfo()
	{
		std::cout << "Name: " << getGoodsName() << std::endl;
		std::cout << "Company Seller: " << getGoodsCompanySeller() << std::endl;
		std::cout << "Discription: " << getGoodsDescription() << std::endl;
		std::cout << "Weight: " << getGoodsWeight() << std::endl;
		std::cout << std::endl;
	}

	Goods::Goods()
	{
		strcpy_s(m_GoodsName, "No Name");
		strcpy_s(m_GoodsCompanySeller, "No Seller");
		strcpy_s(m_GoodsDescription, "No Discription");
		m_GoodsWeight = 0;
	}

	Goods::Goods(char GoodsName[], char GoodsCompanySeller[], char GoodsDescription[], int GoodsWeight)
	{
		strcpy_s(m_GoodsName, GoodsName);
		strcpy_s(m_GoodsCompanySeller, GoodsCompanySeller);
		strcpy_s(m_GoodsDescription, GoodsDescription);
		m_GoodsWeight = GoodsWeight;
	}

	Goods::~Goods() {
	
	}

}