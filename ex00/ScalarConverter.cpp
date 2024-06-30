#include "ScalarConverter.h"

const char *ScalarConverter::pseudof[3] = {"+inff", "-inff", "nan"};
const char *ScalarConverter::pseudod[3] = {"+inf", "-inf", "nan"};

void ScalarConverter::convert(std::string literal) {
	if (!validateLiteral(literal)) {
		std::cout << "Invalid argument." << std::endl;
		return ;
	}

	int type = getType(literal);
	switch (type) {
		case CHAR:
			std::cout << "CHAR" << std::endl;
			break;
		case INT:
			std::cout << "INT" << std::endl;
			break;
		case FLOAT:
			std::cout << "FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "DOUBLE" << std::endl;
			break;
		case PSEUDOF:
			std::cout << "PSEUDOF" << std::endl;
			break;
		case PSEUDOD:
			std::cout << "PSEUDOD" << std::endl;
			break;
		default:
			std::cout << "Cannot find valid type." << std::endl;
	}
}

bool ScalarConverter::validateLiteral(std::string literal) {
	if (literal.empty() || literal.find_first_of("+-") != literal.find_last_of("+-"))
		return false;
	return true;
}


int ScalarConverter::getType(std::string literal) {
	if (checkChar(literal))
		return CHAR;
	if (checkFloat(literal))
		return FLOAT;
	if (checkDouble(literal))
		return DOUBLE;
	if (checkInt(literal))
		return INT;
	if (checkPseudof(literal))
		return PSEUDOF;
	if (checkPseudod(literal)) {
		return PSEUDOD;
	}

	return -1;
}


bool ScalarConverter::checkChar(std::string literal) {
	if (literal.length() > 1 || isdigit(literal.c_str()[0])) {
		return false;
	}
	if (isprint(literal.c_str()[0])) {
		return true;
	}

	return false;
}

bool ScalarConverter::checkFloat(std::string literal) {
	if (literal.find(".") > 0
		&& literal.find_first_of(".") == literal.find_last_of(".")
		&& literal.find("f") == literal.length() - 1
		&& literal.find_first_of("f") == literal.find_last_of("f")
		&& literal.find("f") - literal.find(".") > 1
		&& literal.find_first_not_of("+-0123456789f.") == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::checkDouble(std::string literal) {
	if (literal.find(".",0) > 0 && literal.find(".", 0) < literal.length() - 1
		&& literal.find_first_of(".") == literal.find_last_of(".")
		&& literal.find_first_not_of("+-0123456789.") == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::checkInt(std::string literal) {
	if (literal.find_first_not_of("+-0123456789") == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::checkPseudof(std::string literal) {
	for (int i = 0; i < 3; i++) {
		if (literal == pseudof[i])
			return true;
	}
	return false;
}

bool ScalarConverter::checkPseudod(std::string literal) {
	for (int i = 0; i < 2; i++) {
		if (literal == pseudod[i])
			return true;
	}
	return false;
}






