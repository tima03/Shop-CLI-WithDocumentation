#pragma once

namespace STD
{
	class ItemMenu
	{
		typedef int (*Func)();
	private:
		const char* m_itemName = nullptr;
		Func m_funct = nullptr;
		bool m_activeStatus = true;
	public:
		ItemMenu();
		ItemMenu(const ItemMenu& base);
		ItemMenu(const char* itemName, Func funct, bool status = true);
		virtual void showItemName();
		virtual int run();
		virtual const char* getItemName();
		virtual void setActiveStatus(bool key);
		void setTitle(const char* title);
		void setFunction(Func foo);
		virtual bool getActiveStatus();
	};
}