// Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int day, month, year;
    cout << "Enter date: ";
	cin >> day >> month >> year;
	int dist = 0;
	for (int i = 1800; i < year; i++) {
		if (((i % 100 == 0) && (i % 400 == 0)) || (i % 4 == 0)) {
			dist += 2;
		}
		else {
			dist += 1;
		}
	}

	int days = 0;

	switch (month) {
		case(2): {
			days += 31;
			break;
		}
		case(3): {
			days += (31 + 28);
			break;
		}
		case(4): {
			days += (31 + 28 + 31);
			break;
		}
		case(5): {
			days += (31 + 28 + 31 + 30);
			break;
		}
		case(6): {
			days += (31 + 28 + 31 + 30 + 31);
			break;
		}
		case(7): {
			days += (31 + 28 + 31 + 30 + 31 + 30);
			break;
		}
		case(8): {
			days += (31 + 28 + 31 + 30 + 31 + 30 + 31);
			break;
		}
		case(9): {
			days += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31);
			break;
		}
		case(10): {
			days += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
			break;
		}
		case(11): {
			days += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
			break;
		}
		case(12): {
			days += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
			break;
		}
	}

	if ((month > 2) && (((year % 100 == 0) && (year % 400 == 0)) || (year % 4 == 0))) {
		days++;
	}

	dist += days % 7;

	cout << (dist % 7);
}
