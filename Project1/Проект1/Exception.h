#pragma once
#include<exception>
#include<string>
//����-����������
class CException:public std::exception
{
	std::string message;
public:
	CException(const std::string& msg);
	//
	//������� ������� ����������� �������
	virtual const char* what() const noexcept override;
};

