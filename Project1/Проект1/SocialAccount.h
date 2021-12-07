#pragma once
#include "Account.h"
class CSocialAccount: virtual public  CAccount
{protected:
	double socialPercentAdd; // ������� ��� ����������� �� �������(������� � �����) : 0.01 == 1 %
public:
	// ����������� + ���������� ����������
	CSocialAccount();
	virtual ~CSocialAccount();
	// �������� �������, �� ����� �������������
	virtual void InputMoney(double m); // �������� �� �������
	virtual void PayUtilities(double m);// ������ ����������� ������
	// ��������� ������� ����� �����, ��� ���� �������������
	virtual void AddPercents(); // ����������� ������� � ������� �� ����
};