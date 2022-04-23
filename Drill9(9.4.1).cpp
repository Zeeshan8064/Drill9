#include"std_lib_facilities.h"

struct Date {
	int y;
	int m;
	int d;
};

Date today;
Date tomorrow;

void init_day(Date& dd, int y, int m, int d) {
	if (y < 1900 || y>2018)
		cout << "Error, Invalid Year!" << endl;
	else if (m < 1 || m > 12)
		cout << "Error, Invalid Month!" << endl;
	else if (d < 1 || d > 31)
		cout << "Error, Invalid Date!" << endl;
	else {
		dd.y = y;
		dd.m = m;
		dd.d = d;
	}
	return;
}

void add_day(Date dd, Date& dd_copy, int n) {
	bool lastDay = false;
	bool endyear = false;

	for (int i = 0; i < n; ++i) {
		if (dd.d == 31)
			lastDay = true;
		dd.d = (dd.d == 31) ? 1 : ++dd.d;
		
		if (lastDay) {
			lastDay = false;
			dd.m = (dd.m == 12) ? 1 : ++dd.m;
			if (dd.m == 12) 
				endyear = true;
				if (endyear) {
					endyear = false;
					++dd.y;
				}
			}
		}
	dd_copy = dd;
	}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.d << ", " << d.m << ", " << d.y << endl;
}

int main() {
	//initialise today with June 25 1978
	init_day(today, 1978, 6, 25);

	//assign by copying and increase by 1 day
	add_day(today, tomorrow, 1);

	//print out results
	cout << "Today: " << today << endl;
	cout << "The year Today: " << today.y << endl;
	cout << "The month Today: " << today.m << endl;
	cout << "The day Today: " << today.d << endl;
	cout << "\nTomorrow: " << tomorrow << endl;
	cout << "The year Tomorrow: " << tomorrow.y << endl;
	cout << "The month Tomorrow: " << tomorrow.m << endl;
	cout << "The day Tomorrow: " << tomorrow.d << endl;

	keep_window_open();

	return 0;
}
