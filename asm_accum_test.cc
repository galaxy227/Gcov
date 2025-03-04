#include "Rainfall.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void simulate_input(vector<int>& rainyDays, vector<int>& totalDays, vector<int> input) {
    rainyDays.clear();
    totalDays.clear();
    for (int data : input) {
        if (data >= 0) rainyDays.push_back(data);
        totalDays.push_back(data);
    }
}

void run_test(const string& test_name, bool condition) {
    cout << test_name << ": " << (condition ? "PASSED" : "FAILED") << endl;
}

int main() {
	Rainfall::print_user_prompt();
    vector<int> rainyDays, totalDays;

    // Test 1: Average Daily Rainfall
    simulate_input(rainyDays, totalDays, {1,2,3,4,5,6,7,8,9,-1});
    int sum = asm_accum(totalDays.data(), totalDays.size());
	//cout << "DEBUG: Total sum: " << sum << endl;
    int expected_avg = 4;
    run_test("Average Daily Rainfall", sum / totalDays.size() == expected_avg);

    // Test 2: Average Rainfall on Rainy Days
    simulate_input(rainyDays, totalDays, {1,2,3,4,5,6,7,8,9,-1});
    int rainy_sum = asm_accum(rainyDays.data(), rainyDays.size());
	//cout << "DEBUG: Total rainy sum: " << rainy_sum << endl;
    expected_avg = 5;
    run_test("Average Rainy Days", rainy_sum / rainyDays.size() == expected_avg);

    // Test 3: Maximum Rainfall
    rainyDays = {0,1,2,3,4,5,6,7,8,9};
    int max_rainfall = *max_element(rainyDays.begin(), rainyDays.end());
    run_test("Maximum Rainfall", max_rainfall == 9);


    // Test 4: Sorting Top 5 Rainfall Days
    rainyDays = {5, 10, 50, 20, 30, 40};
    sort(rainyDays.rbegin(), rainyDays.rend());
    vector<int> expected = {50, 40, 30, 20, 10};
    bool top5_correct = true;
    for (size_t i = 0; i < 5; i++) {
        if (rainyDays[i] != expected[i]) {
            top5_correct = false;
            break;
        }
    }
    run_test("Top 5 Rainfall Sorting", top5_correct);

    return 0;
}

