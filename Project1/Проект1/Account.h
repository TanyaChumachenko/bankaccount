#pragma once
#include <iostream>
#include <string.h>
#include<sstream>
class CAccount
{
protected:
	double balance;
	double CommisionPercent; // ������� ���� ����� �� �������� (������� � �����): 0.01 == 1 %
	std::string TransactionStory; // ������ ���������� �� �������
	std::string pip; // ������� �������

public:
	CAccount();
	CAccount(std::string name);
	virtual ~CAccount();
	// ������� ������ �����
	double GetBalance(); // ��������� ������� �� �������
	std::string GetTransactionStory(); // �������� ������ ���������� �� �������
	std::string GetPIP(); // �������� ���i �������� �������
	bool isEnoughMoney(double attempt); //�� ��������� ����� �� �������
	void AddToStory(std::string text); // ��������� ������ � ����� �����
	// �������� �������, �� ����� ������������� � �������� ������
	virtual void InputMoney(double m) = 0; // �������� �� �������
	virtual void PayUtilities(double m) = 0;// ������ ����������� ������
	virtual void OutputMoney(double m); // ������ ������
	//��������� ����� � ������ ������� �� ����� - ���������� �� ������ �������
	friend void Transaction(CAccount * p1, CAccount * p2, double sum);
};
template<class T>
std::string toStringg(const T&value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}