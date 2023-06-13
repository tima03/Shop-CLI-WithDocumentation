#include <iostream>
#include"Sale.h"

namespace STD {

	Sale::Sale() {
		m_GoodsCountAll = 0;
		m_GoodsCountCart = 0;
	}

	Sale::Sale(Goods* cartlist, int goodscount) {
		m_CartList = cartlist;
		m_GoodsCountAll = goodscount;
	}

	Sale::~Sale() {
		
	}

	void Sale::setGoodsList(Goods* cartlist) {
		m_CartList = cartlist;
	};

	void Sale::setGoodsCountAll(int goodscount) {
		m_GoodsCountAll = goodscount;
	}

	void Sale::setGoodsCountCart(int goodscount) {
		m_GoodsCountCart = goodscount;
	}

	Goods* Sale::getGoodsList() {
		return m_GoodsListT;
	}

	int Sale::getGoodsCountAll() {
		return m_GoodsCountAll;
	}

	int Sale::getGoodsCountCart() {
		return m_GoodsCountCart;
	}

	void Sale::AddToCart(int key,Goods* list) {
		Goods goods = list[key];
		if (m_CartList != nullptr)
		{
			Goods* temp = new Goods[m_GoodsCountCart + 1];
			for (int i = 0; i < m_GoodsCountCart; i++)
			{
				temp[i] = m_CartList[i];
			}
			temp[m_GoodsCountCart] = goods;
			m_CartList = temp;
		}
		else
		{
			m_CartList = new Goods[1];
			m_CartList[0] = goods;
		}
		m_GoodsCountCart++;
	}

	void Sale::ShowCartList() {
		std::cout << "Goods list of Cart "<< std::endl;

		for (int i = 0; i < m_GoodsCountCart; i++)
		{
			std::cout << "Name: " << m_CartList[i].getGoodsName() << std::endl;
		}
	}
}