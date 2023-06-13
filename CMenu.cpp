#pragma once
#include "CMenu.h"
#include "AbstractItemMenu.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>
#include "StrPainter.h"

namespace STD
{
	CMenu::CMenu(const char* title, ItemMenu* items, size_t countItems)
	{
		m_title = title;
		m_items = items;
		m_count = countItems;

	}

	int CMenu::getSelect()
	{
		return m_select;
	}

	bool CMenu::getRunningStatus()
	{
		return m_running;
	}

	const char* CMenu::getTitle()
	{
		return m_title;
	}

	size_t CMenu::getCount()
	{
		return m_count;
	}
	ItemMenu* CMenu::getItems()
	{
		return m_items;
	}

	void CMenu::print()
	{
		cls();
		setColor(Red, Black);
		std::cout << m_title << " [" << m_arrowPos << "] " << "Items: " << m_count << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < getCount(); i++)
		{
			if (m_items[i].getActiveStatus() == true) { setColor(White, Black); }
			else { setColor(DarkGray, Black); }
			if (m_arrowPos != i)
			{
				std::cout << "  " << m_items[i].getItemName() << std::endl;
			}
			else
			{
				std::cout << "->" << m_items[i].getItemName() << std::endl;
			}

		}
	}


	void CMenu::executeCmd()
	{
		cls();
		*m_globalIndex = m_arrowPos;
		m_select = m_items[m_arrowPos].run();
		if (m_select == 0)
		{
			m_running = false;
		}
	}

	int CMenu::callback()
	{
		switch (_getch()) {
		case 72: //up
			if (m_arrowPos != 0) { m_arrowPos--; }
			else { m_arrowPos = m_count - 1; }
			break;
		case 80: //down
			if (m_arrowPos != m_count - 1) { m_arrowPos++; }
			else { m_arrowPos = 0; }
			break;
		case 13: //enter
			if (m_items[m_arrowPos].getActiveStatus() == true) { executeCmd(); }
			break;
		case 27: //esc
			exit();
			break;
		default:
			return -1;
		}

	}
	void CMenu::run(bool once)
	{
		m_running = true;
		if (m_count > 0)
		{
			//system("cls");
			print();
			while (m_running == true)
			{

				if (callback() != -1)
				{
					cls();
					print();
				}
				if (once == true && m_select != -1)
				{
					m_running = false;
				}
			}
		}
		else
		{
			setColor(Red, Black);
			for (int i = 0; i < PAUSE; i++)
			{
				std::cout << "List is Empty " << std::endl;
				std::cout << "   " << PAUSE - i << std::endl;
				Sleep(1000);
				cls();
			}

		}
	}

	void CMenu::exit()
	{
		m_running = false;
	}

	void CMenu::setIndexAdress(int* index)
	{
		m_globalIndex = index;
	}

}

	