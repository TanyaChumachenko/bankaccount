#include "Exception.h"
CException::CException(const std::string& msg) {
	this->message = msg;
}
const char* CException::what() const noexcept
{
	return message.c_str();
}