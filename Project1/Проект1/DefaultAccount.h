#pragma once
#include"Account.h"
class CDefaultAccount :virtual public  CAccount
{
public:
	// конструктор + віртуальний деструктор
	CDefaultAccount();
	virtual ~CDefaultAccount();
	// віртуальні функції, які треба перевизначити
	virtual void InputMoney(double m); // покласти на рахунок
	virtual void PayUtilities(double m);// оплата комунальних послуг
};
//-----------------------------------------------------------------
