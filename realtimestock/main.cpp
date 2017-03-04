#include "StockQuote.h"
#include <iostream>
#include <string>

int main() {
	StockQuote * quote = new StockQuote();
	std::string testLink = "http://finance.google.com/finance/info?q=NVDA";
	std::cout << quote->getPrice(quote->getNewStockData(testLink)) << std::endl;
	while (1);
	return 0;
}