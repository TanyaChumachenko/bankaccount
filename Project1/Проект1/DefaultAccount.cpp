#include "DefaultAccount.h"

CDefaultAccount::CDefaultAccount()
{
	CommisionPercent = 0.02;
	TransactionStory = "\n---------------------------------------------------------------- \n\t""\t������� �������";
}
//-----------------------------------------------------------------
CDefaultAccount::~CDefaultAccount()
{}
//-----------------------------------------------------------------
void CDefaultAccount::InputMoney(double m) // �������� �� �������
{
	// ����� �� ���������� �������, ��� ���� �� � ��� ��
	CAccount::InputMoney(m);
	if (m > 0) {
		balance += (m - m * CommisionPercent);
		AddToStory("\n������: ������\r\n�����: " + toStringg(m *CommisionPercent));
			
		AddToStory("\n������� �� �������: " + toStringg(balance));
	}
	else AddToStory("������: ��������. �� ����� ��������� �� ���� ����\n");
}
//-----------------------------------------------------------------
void CDefaultAccount::PayUtilities(double m)// ������ ����������� ������
{
	AddToStory("\n---------------------------------------------------------------- \n");
		
		AddToStory("\r\n��������: ������ ����������� ������\r\n�� ������: " +toStringg(m));
	if (isEnoughMoney(m + m * CommisionPercent)) {
		balance -= m + m * CommisionPercent;
		AddToStory("\n������: ������\r\n�����: " + toStringg(m *CommisionPercent));
		AddToStory("\n������� �� �������: " + toStringg(balance));
	}
	else AddToStory("\n������: ��������. ����������� ����� ��� ��� ��������� ��������\n");
		
}

