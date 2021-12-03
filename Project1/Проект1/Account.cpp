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
double CAccount::GetBalance() // ��������� ������� �� �������
{
	return balance;
}
//-----------------------------------------------------------------
bool CAccount::isEnoughMoney(double attempt) //�� ��������� ����� �� �������

{
	return balance >= attempt;
}
//-----------------------------------------------------------------
// ������ ������
void CAccount::OutputMoney(double m) 
{
	if (m > 0)
	{
		this->AddToStory("\n---------------------------------------------------------------- \n");
			
			this->AddToStory("\n��������: ������ ������\n");
		//������ �������� ��� ������� �� ������
		if (isEnoughMoney(m)) {
			balance -= m;
			this->AddToStory("\n������: ������\r\n������� �� �������: " + toStringg(this->balance));
		}
		else
			this->AddToStory("\n������: ��������.\r\n ����������� ����� ��� ��������� ��������\n");
				
	}
}
//-----------------------------------------------------------------
std::string CAccount::GetTransactionStory() // �������� ������ ���������� �� �������
{
	return TransactionStory;
}
std::string CAccount::GetPIP() // �������� ���i �������� �������
{
	return pip;
}
//-----------------------------------------------------------------
void CAccount::InputMoney(double m) // �������� �� �������
{
	AddToStory("\r\n---------------------------------------------------------------- \n");
	AddToStory("\n��������: ���������� �������\r\n���� ����������: " + toStringg(m));
}
//-----------------------------------------------------------------
void CAccount::AddToStory(std::string text) // ��������� ������ � ����� �����
{
	TransactionStory += text;
	TransactionStory += "\r\n";
}
//-----------------------------------------------------------------
void Transaction(CAccount * p1, CAccount * p2, double sum)
{
	// �����Ҳ���² �������� �� ������� ��� ��̲Ѳ�
	p1->AddToStory("\n----------------------------------------------------------------\n");
		
		p1->AddToStory("\n��������: ������� �� ����� �������\r\n���� ��������: " + toStringg(sum));
	if (p1->isEnoughMoney(sum)) {
		p1->balance -= sum;
		p2->balance += sum;
		p1->AddToStory("\n������: ������\n");
		p1->AddToStory("\n������� �� �������: " + toStringg(p1->balance));
			
		p2->AddToStory("\n---------------------------------------------------------------- \n"
			
			"\r\n��������: ��������� ����� � ������ �������\r\n"
			"���� ��������: " + toStringg(sum) +
			"\r\n������: ������. \r\n������� �� �������: " + toStringg(p2 ->balance));

	}
	else p1->AddToStory("\r\n������: ��������. \r\n����������� ����� ��� ��������� ��������\n");
		
}