#pragma once
#include "Account.h"
class CSocialAccount: virtual public  CAccount
{protected:
	double socialPercentAdd; // відсоток для нарахування на залишок(поданий у сотих) : 0.01 == 1 %
public:
	// конструктор + віртуальний деструктор
	CSocialAccount();
	virtual ~CSocialAccount();
	// віртуальні функції, які треба перевизначити
	virtual void InputMoney(double m); // покласти на рахунок
	virtual void PayUtilities(double m);// оплата комунальних послуг
	// віртуальна функція цього класу, яка буде перевизначена
	virtual void AddPercents(); // нарахування відсотків з залишку на карті
};