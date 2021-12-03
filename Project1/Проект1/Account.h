#pragma once
#include <iostream>
#include <string.h>
#include<sstream>
class CAccount
{
protected:
	double balance;
	double CommisionPercent; // відсоток комісії банку на послгуги (поданий у сотих): 0.01 == 1 %
	std::string TransactionStory; // історія транзакцій по рахунку
	std::string pip; // власник рахунку

public:
	CAccount();
	CAccount(std::string name);
	virtual ~CAccount();
	// звичайні методи класу
	double GetBalance(); // перевірити залишок на рахунку
	std::string GetTransactionStory(); // отримати історію транзакцій по рахунку
	std::string GetPIP(); // отримати данi власника рахунку
	bool isEnoughMoney(double attempt); //чи достатньо коштів на рахунку
	void AddToStory(std::string text); // додавання тексту в кінець історії
	// віртуальні функції, які треба перевизначити у похідних класах
	virtual void InputMoney(double m) = 0; // покласти на рахунок
	virtual void PayUtilities(double m) = 0;// оплата комунальних послуг
	virtual void OutputMoney(double m); // видати готівку
	//перевести гроші з одного рахунку на інший - реалізовано як дружню функцію
	friend void Transaction(CAccount * p1, CAccount * p2, double sum);
};
template<class T>
std::string toStringg(const T&value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}