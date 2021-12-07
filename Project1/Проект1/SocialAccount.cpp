#include "SocialAccount.h"
CSocialAccount::CSocialAccount()
{
	CommisionPercent = 0;
	socialPercentAdd = 0.01;
	TransactionStory = "\n---------------------------------------------------------------- \n\t""\t���������� �������";
	
}
//-----------------------------------------------------------------
CSocialAccount::~CSocialAccount()
{}
//-----------------------------------------------------------------
void CSocialAccount::InputMoney(double m) // �������� �� �������
{
	// � ����������� - ��� ���� ��������� �� �������
	CAccount::InputMoney(m);
	if (m > 0)
	{
		balance += m;
		AddToStory("\n������: ������.\r\n����� ²������.\n");
		AddToStory("\r\n������� �� �������: " + toStringg(balance));
	}
	else AddToStory("\r\n������: ��������.\r\n�� ����� ��������� �� ���� ����\n");
}
//-----------------------------------------------------------------
void CSocialAccount::PayUtilities(double m) // ������ ����������� ������
{
	AddToStory("\n---------------------------------------------------------------- \n");
		
		AddToStory("\r\n��������: ������ ����������� ������\r\n�� ������: " + toStringg(m));
			
	if (isEnoughMoney(m)) {
		balance -= m;
		AddToStory("\n������: ������\r\n����� ²������.\n");
		AddToStory("\n������� �� �������: " + toStringg(balance));
	}
	else AddToStory("\n������: ��������. ����������� ����� ��� ��������� ��������\n");
		
}
//-----------------------------------------------------------------
void CSocialAccount::AddPercents() // ����������� ������� � ������� �� ����
{
	if (balance != 0) {
		balance += balance * socialPercentAdd;
		AddToStory("\n---------------------------------------------------------------- \n");
		AddToStory("\n��������: ����������� ������� �� ������� �� ����\n");
		AddToStory("\n����������� �������:" + toStringg(balance*socialPercentAdd));
		AddToStory("\n������: ������\n");
		AddToStory("\n������� �� �������: " + toStringg(balance));
	}
}
