#include <iostream>
#include "AbstractItemMenu.h"

namespace STD
{
	ItemMenu::ItemMenu()
	{
		
	}


	ItemMenu::ItemMenu(const ItemMenu& base)
	{
		m_itemName = base.m_itemName;
		m_funct = base.m_funct;
		m_activeStatus = base.m_activeStatus;
	}

	ItemMenu::ItemMenu(const char* itemName, Func funct, bool status)
	{
		m_itemName = itemName;
		m_funct = funct;
		m_activeStatus = status;
	}


	const char* ItemMenu::getItemName()
	{
		return m_itemName;
	}

	void ItemMenu::showItemName()
	{
		std::cout << m_itemName;
	}

	int ItemMenu::run()
	{
		return m_funct();
	}

	void ItemMenu::setActiveStatus(bool key)
	{
		m_activeStatus = key;
	}

	bool ItemMenu::getActiveStatus()
	{
		return m_activeStatus;
	}

	void ItemMenu::setTitle(const char* title)
	{
		m_itemName = title;
	}

	void ItemMenu::setFunction(Func foo)
	{
		m_funct = foo;
	}
}