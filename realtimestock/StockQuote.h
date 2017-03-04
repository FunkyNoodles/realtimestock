#pragma once

#include <string>
#include "TimeSeries.h"
#include <rapidjson\document.h>

class StockQuote
{
public:
	StockQuote();
	~StockQuote();

	std::string getNewStockData(std::string url);
	double getPrice(std::string stockData);
	std::string getId(std::string stockData);
	std::string getExchange(std::string stockData);
	double getChange(std::string stockData);
	double getPercentChange(std::string stockData);

private:
	TimeSeries * timeSeries;
	static size_t curlWriteCallback(void * contents, size_t size, size_t nmemb, void * userp);
};

