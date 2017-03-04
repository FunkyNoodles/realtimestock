#pragma once

#include <vector>

class TimeSeries
{
public:
	TimeSeries();
	~TimeSeries();

	std::vector<double> value;
	std::vector<double> ema;

private:
	const int VECTOR_RESERVE_SIZE = 100000;
};

