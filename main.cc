#include "rainfall.h"
#include <iostream>
#include <chrono>
using Time = std::chrono::high_resolution_clock::time_point;
using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<float>;
using namespace std;

// Version used to identify rainfall program in benchmark file
static const int version = 1;

int main() {
	// Start benchmark
	Time start_time = Clock::now();	

	// Rainfall
	vector<int> rainyDays;
	vector<int> totalDays;

	Rainfall::init_data(rainyDays, totalDays);

	int userChoice = 0;

	while (userChoice < 1 or userChoice > 6) {
		Rainfall::print_user_prompt();	

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

				Rainfall::print_user_prompt();

				cin >> userChoice;
			}
		}
		//Else if the user wants avg daily rainfall...
		else if (userChoice == 1) {
			Rainfall::print_avg_daily(totalDays);
		}
		//Else if the user wants avg rainfall on rainy days...
		else if (userChoice == 2) {
			Rainfall::print_avg_rainy(rainyDays);
		}
		//Else if the user wants total number that has days...
		else if (userChoice == 3) {
			Rainfall::print_total_rainfall(rainyDays, totalDays);
		}
		//Else if the user wants max rainfall value...
		else if (userChoice == 4) {
			Rainfall::print_max_rainfall(rainyDays);
		}
		//Else if the user wants top 5 days of rain...
		else if (userChoice == 5) {
			Rainfall::print_top_rainfall(rainyDays);
		}
		//Else if user wants to quit, quit.
		else if (userChoice == 6) {
			break;
		}

		userChoice = 0;
	}

	// End benchmark
	Duration duration = Clock::now() - start_time;
	Rainfall::write_benchmark(version, duration.count(), totalDays);
}
