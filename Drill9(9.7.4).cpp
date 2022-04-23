
#include "std_lib_facilities.h"

enum class Month {
	jan = 1, feb, mar, apr, may, june, jul, aug, sept, oct, nov, dec
};

class Date {

public:
	Date(int y, Month m, int d);
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

	Month month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

private:
	int y, d;
	Month m;
};

Date::Date(int yy, Month mm, int dd) {
	int yearMin(1900), yearMax(3000);
	if (yy > yearMax || yy < yearMin)
		cout << "Invalid year!" << endl;
	if (int(mm) > 12 || int(mm) < 1)
		cout << "Invalid Month!" << endl;
	if (dd > 31 || dd < 1)
		cout << "Invalid date!" << endl;
	else {
		y = yy; m = mm; d = dd;
	}
}

void Date::add_day(int n) {
	if ((d += n) > 31) {
		d = d-31;
		int NextM = int(m) + 1;
		if (NextM > 12) {
			add_month(1);
		}
		else {
			m = Month(NextM);
		}

	}
}

void Date::add_month(int n) {
	int NextM = 0;
	if ((NextM = int(m) + n) > 12) {
		int x = NextM - 12;
		m = Month(x);
		
		add_year(1);
	}
	else
		m = Month(NextM);
}

void Date::add_year(int n) {
	y += n;
	if (y > 3000) {
		cout << "It is not the year 3000! Busted" << endl;
		y -= n;
	}
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << "" << d.year() << "," << int(d.month()) << "," << d.day() << "";
}
int main()
{
	Date today(1978, Month::jan, 30);
	Date tomorrow(today);
	tomorrow.add_day(0);
	tomorrow.add_month(12);
	tomorrow.add_year(0);

	cout << "\nToday=" << today << endl;
	cout << "\nTomorrow=" << tomorrow << endl;

	//invalid date
	Date invalidDate{ 1300, Month::dec, -4 };

	keep_window_open();
	return 0;
}


