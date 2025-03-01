#ifndef RAINFALL_H
#define RAINFALL_H

#include <vector>

namespace Rainfall {
	void die();
	void init_data(std::vector<int>& rainyDays, std::vector<int>& totalDays);

	void print_user_prompt();
	void print_avg_daily(std::vector<int>& totalDays);
	void print_avg_rainy(std::vector<int>& rainyDays);
	void print_total_rainfall(std::vector<int>& rainyDays, std::vector<int>& totalDays);
	void print_max_rainfall(std::vector<int>& rainyDays);
	void print_top_rainfall(std::vector<int>& rainyDays);

	void write_benchmark(const int version, const float time, std::vector<int>& totalDays);
};

#endif
