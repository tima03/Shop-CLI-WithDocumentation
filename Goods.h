#pragma once
#include "Data.h"

namespace STD {
	class Goods : public Data {
	public:
		Goods();
		Goods(char GoodsName[],char GoodsCompanySeller[],char GoodsDescription[],int GoodsWeight);
		~Goods();

		char* getGoodsName();
		char* getGoodsCompanySeller();
		char* getGoodsDescription();
		int getGoodsWeight();

		void setGoodsName(char name[]);
		void setGoodsCompanySeller(char companyseller[]);
		void setGoodsDescription(char description[]);
		void setGoodsWeight(int weight);

		void showInfo();

	private:
		char m_GoodsName[20];
		char m_GoodsCompanySeller[50];
		char m_GoodsDescription[255];
		int m_GoodsWeight;

	};
}