#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <iostream>

using std::string;

class ExceptionM //: public runtime_error
{
public:
	ExceptionM(string message) //: runtime_error(message)
	{
		std::cout << "Error : " << message.c_str() << std::endl;
	}
};

#endif // EXCEPTION_H
