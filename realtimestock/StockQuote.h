#pragma once

#include <string>
#include "TimeSeries.h"
#include <rapidjson\document.h>
#include <boost\date_time.hpp>

namespace bt = boost::posix_time;

class StockQuote
{
public:
	StockQuote(std::string url);
	~StockQuote();

	std::string getNewStockData(std::string url);
	double getPrice(std::string stockData);
	std::string getId(std::string stockData);
	std::string getExchange(std::string stockData);
	double getChange(std::string stockData);
	double getPercentChange(std::string stockData);
	bt::ptime getTime(std::string stockData);

	bool addNewPoint();

private:
	std::string url;
	TimeSeries * timeSeries;
	static size_t curlWriteCallback(void * contents, size_t size, size_t nmemb, void * userp);
	std::locale timeFormat = std::locale(std::locale::classic(), new bt::time_input_facet("%Y-%m-%dT%H:%M:%SZ"));
};

