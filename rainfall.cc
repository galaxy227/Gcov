#include "rainfall.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

void Rainfall::die() {
	cout << "BAD INPUT!" << endl;
	exit(1);
}
void Rainfall::init_data(vector<int>& rainyDays, vector<int>& totalDays) {
	int data = 0;
	cout << "Please enter daily rainfall data (-1 to quit):" << endl;
	cin >> data;

	while (data != -1) {
		if (data == -1) break;

		//If they enter anything but a number, die.
		if (!cin) {
			die();
		}
		//Else if data is any negative number besides -1.
		else if (data < -1) {
			//While data is a negative number other than -1...
			while (data < -1) {
				//If input is invalid, die.
				if (!cin) die();
				//Else, discard it and reprompt.
				else {
					cin.clear();
					cin.ignore(2200000000, '\n');
					cin >> data;

					if (data == -1) break;
				}
			}
			if (data == -1) break;
		}
		//If add the data point to the vector rainyDays.
		if (data > 0) {
			rainyDays.push_back(data);
		}
		//Keep track of all days.
		totalDays.push_back(data);

		cin >> data;
	}
}
void Rainfall::print_user_prompt() {
	cout << "1) Average daily rainfall" << endl;
	cout << "2) Average rainfall on rainy days" << endl;
	cout << "3) Count of days that had rain" << endl;
	cout << "4) Maximum rainfall" << endl;
	cout << "5) Top 5 days of rain" << endl;
	cout << "6) Quit" << endl;
}
void Rainfall::print_avg_daily(vector<int>& totalDays) {
	if (totalDays.size() == 0) cout << "NO DATA" << endl;
	else cout << (accumulate(totalDays.begin(), totalDays.end(), 0) / totalDays.size()) << endl;
}
void Rainfall::print_avg_rainy(vector<int>& rainyDays) {
	if (rainyDays.size() == 0) cout << "NO DATA" << endl;
	else cout << (accumulate(rainyDays.begin(), rainyDays.end(), 0) / rainyDays.size()) << endl;
}
void Rainfall::print_total_rainfall(vector<int>& rainyDays, vector<int>& totalDays) {
	if (totalDays.size() == 0) cout << "NO DATA" << endl;
	else cout << rainyDays.size() << endl;
}
void Rainfall::print_max_rainfall(vector<int>& rainyDays) {
	if (rainyDays.size() == 0) cout << "NO DATA" << endl;
	else cout << *max_element(rainyDays.begin(), rainyDays.end()) << endl;
}
void Rainfall::print_top_rainfall(vector<int>& rainyDays) {
	if (rainyDays.size() == 0) cout << "NO DATA" << endl;
	else {
		sort(rainyDays.rbegin(), rainyDays.rend());
		if (rainyDays.size() > 5) {
			for (int i = 0; i < 5; i++) {
				cout << rainyDays.at(i) << endl;
			}
		} else {
			for (int i = 0; i < static_cast<int>(rainyDays.size()); i++) {
				cout << rainyDays.at(i) << endl;
			}
		}
	}
}
