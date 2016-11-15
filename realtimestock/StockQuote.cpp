#include "StockQuote.h"
#include <iostream>
#include <curl\curl.h>


StockQuote::StockQuote()
{
	CURL * curl = curl_easy_init();
	if (curl) {
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, "http://finance.google.com/finance/info?q=NVDA");
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		std::cout << res << std::endl;
	}
}


StockQuote::~StockQuote()
{
}
