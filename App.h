#pragma once
#include "Buyer.h"
#include "Employee.h"
#include "Goods.h"

namespace STD
{

	class App
	{
	private:
		Buyer* m_BuyerList = nullptr;
		Goods* m_GoodsList = nullptr;
		Employee* m_EmployeeList = nullptr;

		int m_buyerCount;
		int m_goodsCount;
		int m_employeeCount;

	public:
		App(Buyer* buyer, Goods* goods, Employee* employee);
		~App();

		// Фильтрация по возрасту, оставляет только совершеннолетних
		Buyer* filterBuyer();
		Employee* filterEmployee();

		template <typename T>
		T* filter(T* list, int count);


		Goods* filterGoods(int goodsType); // Фильтрация по товарам

		// Добавляют элементы в конец массива (изначальный массив переписываем в новый + 1)
		int addBuyer(char* tmpName, char* tmpPassword, int* tmpAgee);
		int addEmployee(char* tmpName, char* tmpPassword, int* tmpAge);
		void addGoods(Goods* newGoods);


		void deleteBuyer(int index);
		void deleteGoods(int index);
		void deleteEmployee(int index);
		void showGoodsList();
		void sortGoods(int sortName);

		template <typename T>
		T* deleteItem(int index, T* list, int count);

		// getters
		Buyer* getBuyerList();
		Employee* getEmployeeList();
		Goods* getGoodsList();
		int getBuyerCount();
		int getEmployeeCount();
		int getGoodsCount();

		// setters
		void setBuyerList(Buyer* list, int count);
		void setEmployeeList(Employee* list, int count);
		void setGoodsList(Goods* list, int count);
	};

}