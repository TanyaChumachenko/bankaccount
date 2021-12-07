#pragma once
#include<exception>
#include<string>
//клас-виключення
class CException:public std::exception
{
	std::string message;
public:
	CException(const std::string& msg);
	//
	//функція повертає повідомлення помилки
	virtual const char* what() const noexcept override;
};

