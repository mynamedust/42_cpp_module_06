#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <ostream>


class ScalarConverter {
	static const char *pseudof[3];
	static const char *pseudod[3];
	static bool validateLiteral(std::string literal);
	static int getType(std::string literal);
	static bool checkChar(std::string literal);
	static bool checkInt(std::string literal);
	static bool checkFloat(std::string literal);
	static bool checkDouble(std::string literal);
	static bool checkPseudof(std::string literal);
	static bool checkPseudod(std::string literal);
public:
	enum type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDOF,
		PSEUDOD
	};
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter& other);

	static void convert(std::string literal);
};



#endif
