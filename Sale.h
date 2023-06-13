#pragma once
#include "Data.h"
#include "Goods.h"

namespace STD {

	class Sale: public Data{
	public:
		Sale();
		Sale(Goods* cartlist,int goodscount);
		~Sale();
		
		void AddToCart(int key,Goods* list);
		void ShowCartList();

		void setGoodsList(Goods* cartlist);
		void setGoodsCountAll(int goodscount);
		void setGoodsCountCart(int goodscount);

		Goods* getGoodsList();
		int getGoodsCountAll();
		int getGoodsCountCart();
		//Goods* GetCartList();


		Goods* m_CartList = nullptr;
	private:
		
		Goods* m_GoodsListT = nullptr;
		int m_GoodsCountAll;
		int m_GoodsCountCart;
	};
}
