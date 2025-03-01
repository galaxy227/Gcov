#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <istream>
using namespace std;

void die() {
	cout << "BAD INPUT!" << endl;
	exit(1);
}

int main() {
	int data = 0;
	vector<int> rainyDays;
	vector<int> totalDays;

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

	int userChoice = 0;

	while (userChoice < 1 or userChoice > 6) {
		cout << "1) Average daily rainfall" << endl;
		cout << "2) Average rainfall on rainy days" << endl;
		cout << "3) Count of days that had rain" << endl;
		cout << "4) Maximum rainfall" << endl;
		cout << "5) Top 5 days of rain" << endl;
		cout << "6) Quit" << endl;

		cin >> userChoice;
		//If user's input is invalid, clear it and reprompt.
		if (!cin) {
			exit(1);
		}
		//Else if they choose something outside of 1 - 5...
		else if (userChoice < 1 or userChoice > 6) {
			while (userChoice < 1 or userChoice > 6) {
				cin.clear();
				cin.ignore(2200000000, '\n');

				cout << "1) Average daily rainfall" << endl;
				cout << "2) Average rainfall on rainy days" << endl;
				cout << "3) Count of days that had rain" << endl;
				cout << "4) Maximum rainfall" << endl;
				cout << "5) Top 5 days of rain" << endl;
				cout << "6) Quit" << endl;

				cin >> userChoice;
			}
		}
		//Else if the user wants avg daily rainfall...
		else if (userChoice == 1) {
			if (totalDays.size() == 0) cout << "NO DATA" << endl;
			else cout << (accumulate(totalDays.begin(), totalDays.end(), 0) / totalDays.size()) << endl;
		}
		//Else if the user wants avg rainfall on rainy days...
		else if (userChoice == 2) {
			if (rainyDays.size() == 0) cout << "NO DATA" << endl;
			else cout << (accumulate(rainyDays.begin(), rainyDays.end(), 0) / rainyDays.size()) << endl;
		}
		//Else if the user wants total number that has days...
		else if (userChoice == 3) {
			if (totalDays.size() == 0) cout << "NO DATA" << endl;
			else cout << rainyDays.size() << endl;
		}
		//Else if the user wants max rainfall value...
		else if (userChoice == 4) {
			if (rainyDays.size() == 0) cout << "NO DATA" << endl;
			else cout << *max_element(rainyDays.begin(), rainyDays.end()) << endl;
		}
		//Else if the user wants top 5 days of rain...
		else if (userChoice == 5) {
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
		//Else if user wants to quit, quit.
		else if (userChoice == 6) {
			exit(0);
		}

		userChoice = 0;
	}
}
