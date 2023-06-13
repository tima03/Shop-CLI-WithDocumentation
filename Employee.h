#pragma once
#include"Human.h"
#include "Goods.h"

namespace STD {
	class Employee : public Human {
	public:
		Employee();
		Employee(char name[], char password[], int age);
		~Employee();

		void addNewGoods(char GoodsName[], char GoodsCompanySeller[], char GoodsDescription[], int GoodsWeight);
		void deleteGoods(int GoodsPosition);

		Goods* getGoodsList();
		int getGoodsCount();
		void showGoodsList();
		void setGoodsList(Goods* goods);
		void setGoodsList(Goods* list, int count);
		void setGoodsCount(int count);

	private:
		Goods* m_GoodsList = nullptr;
		int m_GoodsCount;
	};
}