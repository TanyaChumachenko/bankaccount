#pragma once
#include"Account.h"
class CDefaultAccount :virtual public  CAccount
{
public:
	// ����������� + ���������� ����������
	CDefaultAccount();
	virtual ~CDefaultAccount();
	// �������� �������, �� ����� �������������
	virtual void InputMoney(double m); // �������� �� �������
	virtual void PayUtilities(double m);// ������ ����������� ������
};
//-----------------------------------------------------------------
