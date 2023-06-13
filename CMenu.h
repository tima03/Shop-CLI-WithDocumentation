#pragma once
#include "AbstractItemMenu.h"

namespace STD
{
#define pause system("PAUSE")
	// Settings
	const int PAUSE = 3; // Pause in seconds

	class CMenu
	{
	private:
		int m_select = -1; // последний ввод пользователя
		int m_arrowPos = 0;
		bool m_running = false; // отвечать за выполнение меню
		int* m_globalIndex = nullptr;
		const char* m_title = nullptr; // заголовок вашего меню
		size_t m_count = 0; // количество пунктов меню
		ItemMenu* m_items = nullptr; // указатель на массив

	public:
		CMenu(const char* title, ItemMenu* items, size_t countItems); // Constructor
		// -------------------------getters-----------------
		int getSelect(); // get last user input number
		bool getRunningStatus();
		const char* getTitle();
		size_t getCount();
		ItemMenu* getItems();
		// ----------------------setters--------------------

		//-----------------------methods--------------------
		void print();
		void executeCmd(); // Выполняет выбранное задание
		int callback(); // реакция на нажатие клавиш

		void setIndexAdress(int* index);
		void run(bool once = false); // цикл запуска меню
		void exit();

	};
}
