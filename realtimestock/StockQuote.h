#pragma once

#include <string>

class StockQuote
{
public:
	StockQuote();
	~StockQuote();
private:
	std::string readBuffer;
	static size_t curlWriteCallback(void * contents, size_t size, size_t nmemb, void * userp);
};

