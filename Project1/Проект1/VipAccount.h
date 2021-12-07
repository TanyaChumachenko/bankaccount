#pragma once
#include"Account.h"
#include "SocialAccount.h"
#include "DefaultAccount.h"

// ���� � ��������� ������������
class CVipAccount :   public CDefaultAccount, public CSocialAccount
{
private:
	double VipPercentAdd; // ������� ��� ����������� �� ������� (������� � �����): 0.01 == 1 %
	double SumForHigherPercent; // ����, ���� ��� ������������	��������� �������
	double creditLimit; // ��� �� ������������ ��������� �����, ������� ������� ������� � ����
public:
	// ����������� + ���������� ����������
	CVipAccount();
	virtual ~CVipAccount();
	// �������� �������, �� ����� �������������
	virtual void InputMoney(double m); // �������� �� �������
	virtual void PayUtilities(double m);// ������ ����������� ������
	virtual void AddPercents(); // ����������� ������� � �������	�� ����
	virtual void OutputMoney(double m); // ������ ������
};

