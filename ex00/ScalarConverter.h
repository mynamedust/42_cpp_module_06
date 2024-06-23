#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>


class ScalarConverter {
	std::string getType(std::string literal);
	bool checkChar(std::string literal);
	bool checkInt(std::string literal);
	bool checkFloat(std::string literal);
	bool checkDouble(std::string literal);
	bool checkInf(std::string literal);
	bool checkPseudo(std::string literal);
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter& other);

	static void convert(std::string literal);
};



#endif
