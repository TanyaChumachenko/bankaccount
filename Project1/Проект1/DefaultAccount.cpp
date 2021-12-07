#include "DefaultAccount.h"

CDefaultAccount::CDefaultAccount()
{
	CommisionPercent = 0.02;
	TransactionStory = "\n---------------------------------------------------------------- \n\t""\tБазовий рахунок";
}
//-----------------------------------------------------------------
CDefaultAccount::~CDefaultAccount()
{}
//-----------------------------------------------------------------
void CDefaultAccount::InputMoney(double m) // покласти на рахунок
{
	// комісія за поповнення рахунку, так само як і для віп
	CAccount::InputMoney(m);
	if (m > 0) {
		balance += (m - m * CommisionPercent);
		AddToStory("\nСтатус: успішно\r\nКомісія: " + toStringg(m *CommisionPercent));
			
		AddToStory("\nЗалишок на рахунку: " + toStringg(balance));
	}
	else AddToStory("Статус: відхилено. Не можна поповнити на таку суму\n");
}
//-----------------------------------------------------------------
void CDefaultAccount::PayUtilities(double m)// оплата комунальних послуг
{
	AddToStory("\n---------------------------------------------------------------- \n");
		
		AddToStory("\r\nОперація: оплата комунальних послуг\r\nДо сплати: " +toStringg(m));
	if (isEnoughMoney(m + m * CommisionPercent)) {
		balance -= m + m * CommisionPercent;
		AddToStory("\nСтатус: успішно\r\nКомісія: " + toStringg(m *CommisionPercent));
		AddToStory("\nЗалишок на рахунку: " + toStringg(balance));
	}
	else AddToStory("\nСтатус: відхилено. Недостатньо коштів для для здійснення операції\n");
		
}

