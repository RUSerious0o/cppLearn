#pragma once

#include <iostream>
#include <optional>
#include <string>

using namespace std;

struct PhoneNumber {
	int countryCode;
	int cityCode;
	string number;
	optional<int> additionalNumber = nullopt;

	friend ostream& operator << (ostream&, const PhoneNumber&);
	friend bool operator < (const PhoneNumber&, const PhoneNumber&);
	friend bool operator > (const PhoneNumber&, const PhoneNumber&);
	friend bool operator == (const PhoneNumber&, const PhoneNumber&);
};

