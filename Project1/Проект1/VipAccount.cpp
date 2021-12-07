#include "VipAccount.h"
CVipAccount::CVipAccount()
{
	CommisionPercent = 0.02;
	VipPercentAdd = 0.04;
	SumForHigherPercent = 10000;
	creditLimit = 50000;
	TransactionStory = "\n---------------------------------------------------------------- \n\t""\tVIP �������";
}
//-----------------------------------------------------------------
CVipAccount::~CVipAccount()
{}
//-----------------------------------------------------------------
void CVipAccount::InputMoney(double m) // �������� �� �������
{
	// �������� ������ �� ������� � ��̲Ѳ�� ��� ���� �� CDefaultAccount
	CDefaultAccount::InputMoney(m);
}
//-----------------------------------------------------------------
void CVipAccount::PayUtilities(double m)// ������ ����������� ������
{
	std::string money, bal, bal1;
	money = toStringg(m);
	bal = toStringg(fabs(balance));
	bal1 = toStringg(balance);
	// ������ ����������� - ��� ��̲Ѳ�
	if (isEnoughMoney(m)) CSocialAccount::PayUtilities(m);
	else
	{
		AddToStory("\n--------------------------------\n");
		AddToStory("\r\n��������: ������ ����������� ������\r\n�� ������: "+money);
		if ((balance + creditLimit) > m)
		{
			balance -= m;
			AddToStory("\n����������� ������� �����: " + bal);
			AddToStory("\n������: ������. \r\n����� ²������.\n");
			AddToStory("\r\n������� �� �������: " + bal1);
		}
		else AddToStory("\r\n������: ��������.\r\n ����������� ����� ��� ��������� ��������\n");
			
	}
}
//-----------------------------------------------------------------
void CVipAccount::OutputMoney(double m) // ������ ������
{
	std::string bal;
	bal = toStringg(this->balance);
	//������ �������� ��� ������� �� ������
	if (m > 0) {
		this->AddToStory("\n--------------------------------\n");
		this->AddToStory("\r\n��������: ������ ������\n");
		if (isEnoughMoney(m)) {
			balance -= m;
			this->AddToStory("\r\n������: ������\r\n������� �� �������: " +bal);
		}
		else if ((balance + creditLimit) > m) {
			balance -= m;
			this->AddToStory("\r\n������: ������.\r\n����������� ������Ͳ �����\r\n""������� �� �������: " +bal);
		}
		else this->AddToStory("\r\n������: ��������.\r\n����������� ����� ��� ��������� ��������\n");
			
	}
}
void CVipAccount::AddPercents() // ����������� ������� � ������� �� ����
{
	std::string bal,bal1;
	bal = toStringg(balance *VipPercentAdd);
	bal = toStringg(balance);

	if (balance != 0) {
		if (balance > SumForHigherPercent) {
			balance += balance * VipPercentAdd;
			AddToStory("\n----------------------------------------------------------------\n");
 			AddToStory("\r\n��������: ����������� ϲ�������� ������� �� ������� �� ����\n");
   			AddToStory("\r\n����������� �������:" + bal1);
			AddToStory("\r\n������: ������\n");
			AddToStory("\r\n������� �� �������: " + bal);
		}
		else CSocialAccount::AddPercents();
	}
}
