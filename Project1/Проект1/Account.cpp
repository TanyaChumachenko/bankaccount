#include "Account.h"
CAccount::CAccount()
{
	balance = 0;
	CommisionPercent = 0;
	TransactionStory = "";
	pip = "";
}
//-----------------------------------------------------------------
CAccount::CAccount(std::string name)
{
	balance = 0;
	CommisionPercent = 0;
	TransactionStory = "";
	pip = name;
}
//-----------------------------------------------------------------
CAccount::~CAccount()
{ }
//-----------------------------------------------------------------
double CAccount::GetBalance() // перевірити залишок на рахунку
{
	return balance;
}
//-----------------------------------------------------------------
bool CAccount::isEnoughMoney(double attempt) //чи достатньо коштів на рахунку

{
	return balance >= attempt;
}
//-----------------------------------------------------------------
// видати готівку
void CAccount::OutputMoney(double m) 
{
	if (m > 0)
	{
		this->AddToStory("\n---------------------------------------------------------------- \n");
			
			this->AddToStory("\nОперація: видача готівки\n");
		//готівка видається без відсотка за зняття
		if (isEnoughMoney(m)) {
			balance -= m;
			this->AddToStory("\nСтатус: успішно\r\nЗалишок на рахунку: " + toStringg(this->balance));
		}
		else
			this->AddToStory("\nСтатус: відхилено.\r\n Недостатньо коштів для здійснення операції\n");
				
	}
}
//-----------------------------------------------------------------
std::string CAccount::GetTransactionStory() // отримати історію транзакцій по рахунку
{
	return TransactionStory;
}
std::string CAccount::GetPIP() // отримати данi власника рахунку
{
	return pip;
}
//-----------------------------------------------------------------
void CAccount::InputMoney(double m) // покласти на рахунок
{
	AddToStory("\r\n---------------------------------------------------------------- \n");
	AddToStory("\nОперація: поповнення рахунку\r\nСума поповнення: " + toStringg(m));
}
//-----------------------------------------------------------------
void CAccount::AddToStory(std::string text) // додавання тексту в кінець історії
{
	TransactionStory += text;
	TransactionStory += "\r\n";
}
//-----------------------------------------------------------------
void Transaction(CAccount * p1, CAccount * p2, double sum)
{
	// БЕЗГОТІВКОВІ перекази між картами БЕЗ КОМІСІЇ
	p1->AddToStory("\n----------------------------------------------------------------\n");
		
		p1->AddToStory("\nОперація: переказ на інший рахунок\r\nСума переказу: " + toStringg(sum));
	if (p1->isEnoughMoney(sum)) {
		p1->balance -= sum;
		p2->balance += sum;
		p1->AddToStory("\nСтатус: Успішно\n");
		p1->AddToStory("\nЗалишок на рахунку: " + toStringg(p1->balance));
			
		p2->AddToStory("\n---------------------------------------------------------------- \n"
			
			"\r\nОперація: отримання коштів з іншого рахунку\r\n"
			"Сума переказу: " + toStringg(sum) +
			"\r\nСтатус: успішно. \r\nЗалишок на рахунку: " + toStringg(p2 ->balance));

	}
	else p1->AddToStory("\r\nСтатус: відхилено. \r\nНедостатньо коштів для здійснення операції\n");
		
}