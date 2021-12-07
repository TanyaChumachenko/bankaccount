#include "VipAccount.h"
CVipAccount::CVipAccount()
{
	CommisionPercent = 0.02;
	VipPercentAdd = 0.04;
	SumForHigherPercent = 10000;
	creditLimit = 50000;
	TransactionStory = "\n---------------------------------------------------------------- \n\t""\tVIP рахунок";
}
//-----------------------------------------------------------------
CVipAccount::~CVipAccount()
{}
//-----------------------------------------------------------------
void CVipAccount::InputMoney(double m) // покласти на рахунок
{
	// внесення готівки на рахунок З КОМІСІЄЮ так само як CDefaultAccount
	CDefaultAccount::InputMoney(m);
}
//-----------------------------------------------------------------
void CVipAccount::PayUtilities(double m)// оплата комунальних послуг
{
	std::string money, bal, bal1;
	money = toStringg(m);
	bal = toStringg(fabs(balance));
	bal1 = toStringg(balance);
	// оплата комунальних - БЕЗ КОМІСІЇ
	if (isEnoughMoney(m)) CSocialAccount::PayUtilities(m);
	else
	{
		AddToStory("\n--------------------------------\n");
		AddToStory("\r\nОперація: оплата комунальних послуг\r\nДо сплати: "+money);
		if ((balance + creditLimit) > m)
		{
			balance -= m;
			AddToStory("\nВикористано кредитні кошти: " + bal);
			AddToStory("\nСтатус: успішно. \r\nКомісія ВІДСУТНЯ.\n");
			AddToStory("\r\nЗалишок на рахунку: " + bal1);
		}
		else AddToStory("\r\nСтатус: відхилено.\r\n Недостатньо коштів для здійснення операції\n");
			
	}
}
//-----------------------------------------------------------------
void CVipAccount::OutputMoney(double m) // видати готівку
{
	std::string bal;
	bal = toStringg(this->balance);
	//готівка видається без відсотка за зняття
	if (m > 0) {
		this->AddToStory("\n--------------------------------\n");
		this->AddToStory("\r\nОперація: видача готівки\n");
		if (isEnoughMoney(m)) {
			balance -= m;
			this->AddToStory("\r\nСтатус: успішно\r\nЗалишок на рахунку: " +bal);
		}
		else if ((balance + creditLimit) > m) {
			balance -= m;
			this->AddToStory("\r\nСтатус: успішно.\r\nВикористано КРЕДИТНІ кошти\r\n""Залишок на рахунку: " +bal);
		}
		else this->AddToStory("\r\nСтатус: відхилено.\r\nНедостатньо коштів для здійснення операції\n");
			
	}
}
void CVipAccount::AddPercents() // нарахування відсотків з залишку на карті
{
	std::string bal,bal1;
	bal = toStringg(balance *VipPercentAdd);
	bal = toStringg(balance);

	if (balance != 0) {
		if (balance > SumForHigherPercent) {
			balance += balance * VipPercentAdd;
			AddToStory("\n----------------------------------------------------------------\n");
 			AddToStory("\r\nОперація: нарахування ПІДВИЩЕНИХ відсотків на залишок на карті\n");
   			AddToStory("\r\nНарахований відсоток:" + bal1);
			AddToStory("\r\nСтатус: успішно\n");
			AddToStory("\r\nЗалишок на рахунку: " + bal);
		}
		else CSocialAccount::AddPercents();
	}
}
