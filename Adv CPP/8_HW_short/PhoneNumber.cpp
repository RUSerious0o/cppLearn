#include "PhoneNumber.h"

ostream& operator << (ostream& out, const PhoneNumber& number) {
	out << "+" << number.countryCode << "(" << number.cityCode << ")" << number.number;

	if (!number.additionalNumber.has_value()) {
		return out;
	}

	if (number.additionalNumber.value() > 0) {
		out << " " << number.additionalNumber.value();
	}
	return out;
}

bool operator < (const PhoneNumber& number_1, const PhoneNumber& number_2) {
	return	tie(number_1.countryCode, number_1.cityCode, number_1.number, number_1.additionalNumber) <
		tie(number_2.countryCode, number_2.cityCode, number_2.number, number_2.additionalNumber);
}

bool operator > (const PhoneNumber& number_1, const PhoneNumber& number_2) {
	return	tie(number_1.countryCode, number_1.cityCode, number_1.number, number_1.additionalNumber) >
		tie(number_2.countryCode, number_2.cityCode, number_2.number, number_2.additionalNumber);
}

bool operator == (const PhoneNumber& number_1, const PhoneNumber& number_2) {
	return	tie(number_1.countryCode, number_1.cityCode, number_1.number, number_1.additionalNumber) ==
		tie(number_2.countryCode, number_2.cityCode, number_2.number, number_2.additionalNumber);
}