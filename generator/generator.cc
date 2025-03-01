#include <fstream>
#include <iostream>
#include <random>
using namespace std;

/*
If no arguments are specified, default values will be used.

 First argument is input file name
 Second argument is max days
 Third argument is max rainfall
 Fourth argument is seed

Example:
./generator input_file 100 9999 1
*/

void write(ofstream& file, string text) {
	file << text + "\n";
}

int main(int argc, char* argv[]) {
	// Handle user input
	string file_name = "input";
	int max_days = 1'000'000;
	int max_rainfall = 100;
	int seed = 0;
	if (argc > 1) file_name = argv[1];
	if (argc > 2) max_days = atoi(argv[2]);
	if (argc > 3) max_rainfall = atoi(argv[3]);
	if (argc > 4) seed = atoi(argv[4]);
	// Random
    	mt19937 rand(seed);
    	uniform_int_distribution<int> dist(1, max_rainfall);
	// Generate rainfall
    	ofstream file(file_name + ".txt");
	for (int j = 0; j < max_days; j++) {
		float multiplier = dist(rand) / 100.0f;
		int value = dist(rand) * multiplier;
		file << to_string(value) + "\n";
	}
	// Execute commands for rainfall program
	write(file, to_string(-1));
	write(file, to_string(1));
	write(file, to_string(2));
	write(file, to_string(3));
	write(file, to_string(4));
	write(file, to_string(5));
	write(file, to_string(6));
	// Return
    	file.close();
    	return 0;
}
