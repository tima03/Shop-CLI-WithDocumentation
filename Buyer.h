#pragma once
#include "Human.h"
#include "Goods.h"
#include "Sale.h"

namespace STD {
	class Buyer : public Human {
	public:
		Buyer();
		Buyer(char name[], char password[], int age);
		Buyer(char name[], char password[], int age,Goods* goodslist,int goodscount);
		Buyer(Goods* goodslist, int goodscount);
		~Buyer();

		Goods* getGoodsList();
		int getGoodsCount();
		void showGoodsList();
		void sortGoods(int sortName);

		void addNewGoods(char GoodsName[], char GoodsCompanySeller[], char GoodsDescription[], int GoodsWeight);
		void setGoodsList(Goods* goods);
		void setGoodsList(Goods* list, int count);
		void setGoodsCount(int count);

		Sale cart;
		
	private:
		Goods* m_GoodsList = nullptr;
		int m_GoodsCount = 0;
		
	};
}