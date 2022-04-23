#include"std_lib_facilities.h"

struct Date {
	int y,m,d;
	Date(int y, int m, int d);
	void add_day(int n);
	
};

Date today(1978,6,25);
Date tomorrow(today);

Date::Date(int y, int m, int d) {
	if (y < 1900 || y>2018)
		cout << "Error, Invalid Year!" << endl;
	else if (m < 1 || m > 12)
		cout << "Error, Invalid Month!" << endl;
	else if (d < 1 || d > 31)
		cout << "Error, Invalid Date!" << endl;
	else {
		Date::y = y;
		Date::m = m;
		Date::d = d;
	}
	return;
}

void Date::add_day(int n) {
	bool lastDay = false;
	bool endyear = false;

	for (int i = 0; i < n; ++i) {
		if (Date::d == 31)
			lastDay = true;
		Date::d = (Date::d == 31) ? 1 : ++Date::d;

		if (lastDay) {
			lastDay = false;
			Date::m = (Date::m == 12) ? 1 : ++Date::m;
			if (Date::m == 12)
				endyear = true;
			if (endyear) {
				endyear = false;
				++Date::y;
			}
		}
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.d << ", " << d.m << ", " << d.y << endl;
}

int main() {
	//increase day by one
	tomorrow.add_day(1);

	//print out results
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	keep_window_open();

	return 0;
}
