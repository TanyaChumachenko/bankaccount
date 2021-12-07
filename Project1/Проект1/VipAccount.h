#pragma once
#include"Account.h"
#include "SocialAccount.h"
#include "DefaultAccount.h"

// клас з множинним наслідуванням
class CVipAccount :   public CDefaultAccount, public CSocialAccount
{
private:
	double VipPercentAdd; // відсоток для нарахування на залишок (поданий у сотих): 0.01 == 1 %
	double SumForHigherPercent; // сума, після якої нараховується	підвищений відсоток
	double creditLimit; // ліміт на використання кредитних коштів, можливо загнати рахунок в мінус
public:
	// конструктор + віртуальний деструктор
	CVipAccount();
	virtual ~CVipAccount();
	// віртуальні функції, які треба перевизначити
	virtual void InputMoney(double m); // покласти на рахунок
	virtual void PayUtilities(double m);// оплата комунальних послуг
	virtual void AddPercents(); // нарахування відсотків з залишку	на карті
	virtual void OutputMoney(double m); // видати готівку
};

