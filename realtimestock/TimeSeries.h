#pragma once

#include <vector>
#include <boost\date_time.hpp>

namespace bt = boost::posix_time;

class TimeSeries
{
public:
	TimeSeries();
	~TimeSeries();

	std::vector<bt::ptime> time;
	std::vector<double> value;
	std::vector<double> ema;

private:
	const int VECTOR_RESERVE_SIZE = 100000;
};

