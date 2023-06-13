#include <iostream>
#include <fstream>
#include "ProgramStart.h"
#include "AbstractItemMenu.h"
#include "CMenu.h"
#include "Data.h"
#include "App.h"
#include "Goods.h"
#include "Buyer.h"
#include "Employee.h"

namespace STD {

	Buyer* default_buyer = new Buyer((char*)"DefaultBuyer", (char*)"DefaultPass", 18);
	Employee* default_employee = new Employee((char*)"DefaultEmployee", (char*)"DefaultPass", 18);
	Goods* default_goods = new Goods((char*)"DefaultGoods", (char*)"Default Cmpsel", (char*)"DefaultDescription", 20);
	App* app = new App(default_buyer, default_goods, default_employee);

	Buyer* ActiveBuyer = nullptr;
	Employee* ActiveEmployee = nullptr;
	int GLOBAL_INDEX=0;
	int SavedGI = 0;
	bool LoggedBuyer = false;

	char SUPER_USERNAME[] = { "Tim" };
	int SUPER_PASSWORD = 4883;

	void ProgramStart() {
		ItemMenu menuList[]
		{
		ItemMenu("Log in", LogIn),
		ItemMenu("Sign in", SignIn),
		ItemMenu("Save state", SaveState),
		ItemMenu("Load state", LoadState)
		};
		ItemMenu* menuListPointer = menuList;
		CMenu MainMenu("Shop v3.0", menuListPointer, (size_t)sizeof(menuList) / sizeof(menuList[0]));
		MainMenu.setIndexAdress(&GLOBAL_INDEX);
		MainMenu.run();
	}
	
	int AddCart() {
		ActiveBuyer->cart.AddToCart(SavedGI,app->getGoodsList());
		std::cout << "Added to Cart!" << std::endl; 
		pause;
		return 1;
	}

	int ShowGoodsInfo() {
		SavedGI = GLOBAL_INDEX;
		app->getGoodsList()[GLOBAL_INDEX].showInfo();
		pause;
		if (LoggedBuyer) {
			ItemMenu AddToCart[]
			{
				ItemMenu("AddToCart",AddCart)
			};
			ItemMenu* IMPointer0 = &AddToCart[0];
			CMenu SubMenu("Buyer", IMPointer0, (size_t)sizeof(AddToCart) / sizeof(AddToCart[0]));
			SubMenu.setIndexAdress(&GLOBAL_INDEX);
			SubMenu.run();
			pause;
		}
		return 1;
	}

	int ShowGoodsList() {

		ItemMenu* globalGoodsList = new ItemMenu[app->getGoodsCount()];
		for (int i = 0; i < app->getGoodsCount(); i++)
		{
			globalGoodsList[i].setTitle(app->getGoodsList()[i].getGoodsName());
			globalGoodsList[i].setFunction(ShowGoodsInfo);
		}
		CMenu SubMenu("All Goods", globalGoodsList, app->getGoodsCount());
		SubMenu.setIndexAdress(&GLOBAL_INDEX);
		SubMenu.run();
		return 1;
	}

	int SubSortGoods()
	{
		ActiveBuyer->sortGoods(GLOBAL_INDEX);
		std::cout << "Sorted!" << std::endl;
		pause;
		return 1;
	}

	int SortGoodsList() {
		ItemMenu* goodsNameList = new ItemMenu[4];
		for (int i = 0; i < 4; i++)
		{
			goodsNameList[i].setTitle(strSortName[i]);
			goodsNameList[i].setFunction(SubSortGoods);
		}
		CMenu SubMenu("Choose how to sort Gooods", goodsNameList, 4);
		SubMenu.setIndexAdress(&GLOBAL_INDEX);
		SubMenu.run();
		return 1;
	}

	int ShowCart() {
		ActiveBuyer->cart.ShowCartList();
		pause;
		return 1;
	}

	int LogInBuyer() {
		char* tmpName = new char[20];
		char* tmpPassword = new char[20];
		bool Logged = false;

		std::cout << "Input your NickName: "; std::cin >> tmpName; std::cout << std::endl;
		std::cout << "Input your Password: "; std::cin >> tmpPassword;
		for (int i = 0; i < app->getBuyerCount(); i++)
		{
			if (strcmp(app->getBuyerList()[i].getName(), tmpName) == 0)
			{
				std::cout << app->getBuyerList()[i].getPassword() << std::endl;
				if (strcmp(app->getBuyerList()[i].getPassword(), tmpPassword) == 0)
				{
					Logged = true;
					LoggedBuyer = true;
					ActiveBuyer = &app->getBuyerList()[i];
					ActiveBuyer->setGoodsList(app->getGoodsList());
					ActiveBuyer->setGoodsCount(app->getGoodsCount());
					ItemMenu BuyerOptions[]
					{
						ItemMenu("Show All Goods",ShowGoodsList),
						ItemMenu("Sort Goods",SortGoodsList),
						ItemMenu("Show Cart",ShowCart)
					};
					CMenu SubMenu((char*)"Buyer ", BuyerOptions, (size_t)sizeof(BuyerOptions) / sizeof(BuyerOptions[0]));
					SubMenu.setIndexAdress(&GLOBAL_INDEX);
					SubMenu.run();
					break;
				}
			}
		}

		if (!Logged) {
			std::cout << "Incorrect name or password!" << std::endl;
			pause;
		}

		delete[] tmpName;
		return 1;
	}

	int NewGoodsAdd() {
		char* tmpName = new char[20];
		char* tmpCmpnyseller = new char[20];
		char* tmpDiscription = new char[20];
		int* tmpWeight = new int(0);

		std::cin.clear(); 
		std::cin.ignore(32767, '\n');
		std::cout << "Input good name: "; std::cin >> tmpName; std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Input company seller name: "; std::cin >> tmpCmpnyseller; std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Input good discription: "; std::cin >> tmpDiscription; std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Input weight (g.): "; std::cin >> *tmpWeight; std::cout << std::endl;
		
		ActiveEmployee->addNewGoods(tmpName,tmpCmpnyseller ,tmpDiscription, *tmpWeight);
		app->addGoods(&ActiveEmployee->getGoodsList()[ActiveEmployee->getGoodsCount() - 1]);
		std::cout << "Good was created!" << std::endl;

		pause;
		return 1;
	}
	
	int SubDelGoods() {
		app->deleteGoods(GLOBAL_INDEX);
		std::cout << "Goods was deleted!" << std::endl;
		pause;
		return 1;
	}

	int DeleteGoods() {
		ItemMenu* globalGoodsList = new ItemMenu[app->getGoodsCount()];
		for (int i = 0; i < app->getGoodsCount(); i++)
		{
			globalGoodsList[i] = ItemMenu(app->getGoodsList()[i].getGoodsName(), SubDelGoods);
		}
		CMenu SubMenu("Choose Goods to delete from Goods`s List", globalGoodsList, app->getGoodsCount());
		SubMenu.setIndexAdress(&GLOBAL_INDEX);
		SubMenu.run(true);
		return 1;
	}

	int Logs() {
		std::cout << "Логи не найдены..." << std::endl;
		return 1;
	}

	int LogInEmployee() {
		char* tmpName = new char[20];
		char* tmpPassword = new char[20];
		bool Logged = false;

		std::cout << "Input your NickName: "; std::cin >> tmpName; std::cout << std::endl;
		std::cout << "Input your password: "; std::cin >> tmpPassword;
		for (int i = 0; i < app->getEmployeeCount(); i++)
		{
			if (strcmp(app->getEmployeeList()[i].getName(), tmpName) == 0)
			{
				std::cout << app->getEmployeeList()[i].getPassword() << std::endl;
				if (strcmp(app->getEmployeeList()[i].getPassword(), tmpPassword) == 0)
				{
					Logged = true;
					LoggedBuyer = false;
					ActiveEmployee = &app->getEmployeeList()[i];
					ActiveEmployee->setGoodsList(app->getGoodsList());
					ActiveEmployee->setGoodsCount(app->getGoodsCount());
					ItemMenu EmployeeOptions[]
					{
						ItemMenu("Show All Goods",ShowGoodsList),
						//ItemMenu("Sort Goods",SortGoodsList),
						ItemMenu("Add new Goods",NewGoodsAdd),
						ItemMenu("Delete Goods",DeleteGoods)
						//ItemMenu("Show Logs",Logs)
					};
					ItemMenu* IMPointer5 = &EmployeeOptions[0];
					CMenu SubMenu((char*)"Buyer", IMPointer5, (size_t)sizeof(EmployeeOptions) / sizeof(EmployeeOptions[0]));
					SubMenu.setIndexAdress(&GLOBAL_INDEX);
					SubMenu.run();
					break;
				}
			}
		}

		if (!Logged) {
			std::cout << "Incorrect name or password!" << std::endl;
			pause;
		}

		delete[] tmpName;
		return 1;
	}

	int FilterBuyer()
	{
		app->filterBuyer();
		pause;
		return 1;
	}

	int FilterEmployee()
	{
		app->filterEmployee();
		pause;
		return 1;
	}


	int SubDelBuyer()
	{
		app->deleteBuyer(GLOBAL_INDEX);
		std::cout << "Buyer was deleted from the system!" << std::endl;
		pause;
		return 1;
	}

	int DeleteBuyer()
	{
		ItemMenu* BuyerList = new ItemMenu[app->getBuyerCount()];
		for (int i = 0; i < app->getBuyerCount(); i++)
		{
			BuyerList[i] = ItemMenu(app->getBuyerList()[i].getName(), SubDelBuyer);
		}
		CMenu SubMenu("Choose Buyer to delete from User`s List", BuyerList, app->getBuyerCount());
		SubMenu.setIndexAdress(&GLOBAL_INDEX);
		SubMenu.run(true);
		return 1;
	}

	int SubDelEmployee()
	{
		app->deleteEmployee(GLOBAL_INDEX);
		std::cout << "Employee was deleted from the system, but his track are still available!" << std::endl;
		pause;
		return 1;
	}

	int DeleteEmployee()
	{
		ItemMenu* EmployeeList = new ItemMenu[app->getEmployeeCount()];
		for (int i = 0; i < app->getEmployeeCount(); i++)
		{
			EmployeeList[i] = ItemMenu(app->getEmployeeList()[i].getName(), SubDelEmployee);
		}
		CMenu SubMenu("Choose Employee to delete from Employer`s List", EmployeeList, app->getEmployeeCount());
		SubMenu.setIndexAdress(&GLOBAL_INDEX);
		SubMenu.run(true);
		return 1;
	}

	int LogInAdmin()
	{
		char* tmpName = new char[20];
		int tmpPassword = 0;
		std::cin.clear();
		std::cout << "Input your NickName: "; std::cin >> tmpName; std::cout << std::endl;
		std::cout << "Input your Password: "; std::cin >> tmpPassword; std::cout << std::endl;
		for (int i = 0; i < app->getEmployeeCount(); i++)
		{
			if (strcmp(SUPER_USERNAME, tmpName) == 0 && SUPER_PASSWORD == tmpPassword)
			{
				ItemMenu EmployerOptions[]
				{
					ItemMenu("Filter the Buyer",FilterBuyer),
					ItemMenu("Filter the Employee",FilterEmployee),
					ItemMenu("Delete Buyer",DeleteBuyer),
					ItemMenu("Delete Employee",DeleteEmployee)
				//	ItemMenu("Load Data",loadData)
				};
				CMenu SubMenu("Admin", EmployerOptions, (size_t)sizeof(EmployerOptions) / sizeof(EmployerOptions[0]));
				SubMenu.setIndexAdress(&GLOBAL_INDEX);
				SubMenu.run();
				break;
			}
		}
		delete[] tmpName;
		return 1;
	}

	int LogIn() {
		ItemMenu LogInList[]
		{
			ItemMenu("Log In as Buyer",LogInBuyer),
			ItemMenu("Log In as Employee",LogInEmployee),
			ItemMenu("Log In as Admin",LogInAdmin)
		};
		ItemMenu* IMPointer3 = &LogInList[0];
		CMenu SubMenu("Login In", IMPointer3, (size_t)sizeof(LogInList) / sizeof(LogInList[0]));
		SubMenu.setIndexAdress(&GLOBAL_INDEX);
		SubMenu.run();
		return 1;
	}

	int SignInBuyer() {
		char* tmpName = new char[20];
		char* tmpPassword = new char[20];
		int tmpAge = 0;

		std::cout << "Input your NickName: "; std::cin >> tmpName; std::cout << std::endl;
		std::cout << "Input your Password: "; std::cin >> tmpPassword; std::cout << std::endl;
		std::cout << "Input your Age: "; std::cin >> tmpAge; std::cout << std::endl;
		app->addBuyer(tmpName, tmpPassword, &tmpAge);
		
		delete[] tmpName;

		std::cout << "New buyer created!" << std::endl;
		pause;

		return 1;
	}

	int SignInEmployee() {
		char* tmpName = new char[20];
		char* tmpPassword = new char[20];
		int tmpAge = 0;

		std::cout << "Input your NickName: "; std::cin >> tmpName; std::cout << std::endl;
		std::cout << "Input your Password: "; std::cin >> tmpPassword; std::cout << std::endl;
		std::cout << "Input your Age: "; std::cin >> tmpAge; std::cout << std::endl;
		app->addEmployee(tmpName, tmpPassword, &tmpAge);
		
		delete[] tmpName;

		std::cout << "New employee created!" << std::endl;
		pause;

		return 1;
	}

	int SignIn() {

		ItemMenu MenuListSignIn[] = 
		{
		ItemMenu("Buyer", SignInBuyer),
		ItemMenu("Employee", SignInEmployee)
		};

		ItemMenu* IMPointer2 = &MenuListSignIn[0];
		CMenu SignIn("Sign In", IMPointer2, 2);
		SignIn.setIndexAdress(&GLOBAL_INDEX);
		SignIn.run();

		return 1;
	}

	int SaveState() {
		std::ofstream outFile;
		int tmp = app->getGoodsCount();
		std::cout << "Writing last changes." << std::endl;

		// Goods
		outFile.open("Goods.txt", std::ios::binary);
		if (!outFile)
		{
			std::cerr << "Error, can`t open Goods.txt" << std::endl;
			pause;
			return -1;
		}

		outFile.write(reinterpret_cast<char*>(&tmp), sizeof(int));
		for (int i = 0; i < app->getGoodsCount(); i++)
		{
			outFile.write(reinterpret_cast<char*>(&(app->getGoodsList()[i])), sizeof(Goods));
		}
		outFile.close();
		std::cout << "Writing last changes.." << std::endl;

		// Users
		outFile.open("Buyers.txt", std::ios::binary);
		if (!outFile)
		{
			std::cerr << "Error, can`t open Buyers.txt" << std::endl;
			pause;
			return -1;
		}
		tmp = app->getBuyerCount();
		outFile.write(reinterpret_cast<char*>(&tmp), sizeof(int));
		for (int i = 0; i < app->getBuyerCount(); i++)
		{
			outFile.write(reinterpret_cast<char*>(&(app->getBuyerList()[i])), sizeof(Buyer));
			for (int j = 0; j < (app->getBuyerList()[i].getGoodsCount()); j++)
			{
				outFile.write(reinterpret_cast<char*>(&(app->getBuyerList()[i]).getGoodsList()[j]), sizeof(Goods));
			}
		}
		outFile.close();

		std::cout << "Writing last changes..." << std::endl;

		// Employee
		outFile.open("Employee.txt", std::ios::binary);
		if (!outFile)
		{
			std::cerr << "Error, can`t open Employee.txt" << std::endl;
			pause;
			return -1;
		}
		tmp = app->getEmployeeCount();
		outFile.write(reinterpret_cast<char*>(&tmp), sizeof(int));
		for (int i = 0; i < app->getEmployeeCount(); i++)
		{
			outFile.write(reinterpret_cast<char*>(&(app->getEmployeeList()[i])), sizeof(Employee));
			for (int j = 0; j < app->getEmployeeList()[i].getGoodsCount(); j++)
			{
				outFile.write(reinterpret_cast<char*>(&(app->getEmployeeList()[i].getGoodsList()[j])), sizeof(Goods));
			}
		}
		outFile.close();
		std::cout << "Data was saved!" << std::endl;
		pause;
		return 1;
	}

	int LoadState() {
		std::cout << "[Log]-----------------------[Loading data]]-----------------------" << std::endl;
		std::ifstream inFile;
		int tmp;

		// Goods
		inFile.open("Goods.txt", std::ios::binary);
		if (!inFile)
		{
			std::cerr << "Error, can`t open goods.txt" << std::endl;
			pause;
			return -1;
		}
		inFile.read(reinterpret_cast<char*>(&tmp), sizeof(int));
		std::cout << "[Log]Count of Goods: " << tmp << std::endl;
		Goods* tmpGoodsList = new Goods[tmp];
		for (int i = 0; i < tmp; i++)
		{
			inFile.read(reinterpret_cast<char*>(&(tmpGoodsList[i])), sizeof(Goods));
		}
		app->setGoodsList(tmpGoodsList, tmp);
		delete[] tmpGoodsList;
		inFile.close();

		// Buyers
		inFile.open("Buyers.txt", std::ios::binary);
		if (!inFile)
		{
			std::cerr << "Error, can`t open buyers.txt" << std::endl;
			pause;
			return -1;
		}
		inFile.read(reinterpret_cast<char*>(&tmp), sizeof(int));
		std::cout << "[Log]Count of Buyers: " << tmp << std::endl;
		Buyer* tmpBuyerList = new Buyer[tmp];
		for (int i = 0; i < tmp; i++)
		{
			inFile.read(reinterpret_cast<char*>(&(tmpBuyerList[i])), sizeof(Buyer));
			int tmpCount = tmpBuyerList[i].getGoodsCount();
			Goods* tmpGoodsList = new Goods[tmpCount];
			for (int j = 0; j < tmpCount; j++)
			{
				inFile.read(reinterpret_cast<char*>(&tmpGoodsList[j]), sizeof(Goods));
			}
			tmpBuyerList[i].setGoodsList(tmpGoodsList, tmpCount);
			delete[] tmpGoodsList;

		}
		app->setBuyerList(tmpBuyerList, tmp);
		delete[] tmpBuyerList;
		inFile.close();

		// Employee
		inFile.open("Employee.txt", std::ios::binary);
		if (!inFile)
		{
			std::cerr << "Error, can`t open Employee.txt" << std::endl;
			pause;
			return -1;
		}
		inFile.read(reinterpret_cast<char*>(&tmp), sizeof(int));
		std::cout << "[Log]Count of Employee: " << tmp << std::endl;
		Employee* tmpEmpList = new Employee[tmp];
		for (int i = 0; i < tmp; i++)
		{
			inFile.read(reinterpret_cast<char*>(&(tmpEmpList[i])), sizeof(Employee));
			int tmpCount = tmpEmpList[i].getGoodsCount();
			Goods* tmpGoodsList = new Goods[tmpCount];
			for (int j = 0; j < tmpCount; j++)
			{
				inFile.read(reinterpret_cast<char*>(&tmpGoodsList[j]), sizeof(Goods));
			}
			tmpEmpList[i].setGoodsList(tmpGoodsList, tmpCount);
			delete[] tmpGoodsList;
		}
		app->setEmployeeList(tmpEmpList, tmp);
		delete[] tmpEmpList;
		inFile.close();
		std::cout << "[Log][Loading][Done!]" << std::endl;
		pause;
		return 1;
	}

}

		/*
		Employee emp1;
		emp1.addNewGoods((char*)"1", (char*)"1", (char*)"1",1);
		emp1.addNewGoods((char*)"2", (char*)"2", (char*)"2", 2);
		Buyer buyer1(emp1.getGoodsList(),emp1.getGoodsCount());
		std::cout<<buyer1.getGoodsCount()<<std::endl;
		std::cout<<buyer1.getGoodsList() << std::endl;
		buyer1.cart.AddToCart(1, emp1.getGoodsList());
		buyer1.cart.AddToCart(0, emp1.getGoodsList());
		buyer1.cart.AddToCart(0, emp1.getGoodsList());
		buyer1.cart.AddToCart(1, emp1.getGoodsList());
		buyer1.cart.ShowCartList();
		*/

		/*
		int TempIndex = -1;
		MainMenu.m_running = true;
		while (MainMenu.m_running) {
			std::cout << MainMenu;
			std::cin >> MainMenu;
			if (MainMenu.m_select == -1) {
				MainMenu.m_running = false;
			}
			else
			{
				MainMenu.m_items[TempIndex].run();
				system("pause");
			}
		}
		
		[1].printItemName();
		*/