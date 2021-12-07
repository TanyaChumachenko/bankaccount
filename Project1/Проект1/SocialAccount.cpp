#include "SocialAccount.h"
CSocialAccount::CSocialAccount()
{
	CommisionPercent = 0;
	socialPercentAdd = 0.01;
	TransactionStory = "\n---------------------------------------------------------------- \n\t""\tСоціальний рахунок";
	
}
//-----------------------------------------------------------------
CSocialAccount::~CSocialAccount()
{}
//-----------------------------------------------------------------
void CSocialAccount::InputMoney(double m) // покласти на рахунок
{
	// у соціальному - без комісії покласити на рахунок
	CAccount::InputMoney(m);
	if (m > 0)
	{
		balance += m;
		AddToStory("\nСтатус: успішно.\r\nКомісія ВІДСУТНЯ.\n");
		AddToStory("\r\nЗалишок на рахунку: " + toStringg(balance));
	}
	else AddToStory("\r\nСтатус: відхилено.\r\nНе можна поповнити на таку суму\n");
}
//-----------------------------------------------------------------
void CSocialAccount::PayUtilities(double m) // оплата комунальних послуг
{
	AddToStory("\n---------------------------------------------------------------- \n");
		
		AddToStory("\r\nОперація: оплата комунальних послуг\r\nДо сплати: " + toStringg(m));
			
	if (isEnoughMoney(m)) {
		balance -= m;
		AddToStory("\nСтатус: успішно\r\nКомісія ВІДСУТНЯ.\n");
		AddToStory("\nЗалишок на рахунку: " + toStringg(balance));
	}
	else AddToStory("\nСтатус: відхилено. Недостатньо коштів для здійснення операції\n");
		
}
//-----------------------------------------------------------------
void CSocialAccount::AddPercents() // нарахування відсотків з залишку на карті
{
	if (balance != 0) {
		balance += balance * socialPercentAdd;
		AddToStory("\n---------------------------------------------------------------- \n");
		AddToStory("\nОперація: нарахування відсотків на залишок на карті\n");
		AddToStory("\nНарахований відсоток:" + toStringg(balance*socialPercentAdd));
		AddToStory("\nСтатус: успішно\n");
		AddToStory("\nЗалишок на рахунку: " + toStringg(balance));
	}
}
