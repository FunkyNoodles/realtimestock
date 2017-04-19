#include "StockQuote.h"
#include <iostream>
#include <string>
#include <boost/date_time.hpp>
#include <thread>


void updateTicker(std::string link) {
	StockQuote * quote = new StockQuote(link);
	while (true) {
		quote->addNewPoint();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}


int main() {
	std::string testLink = "http://finance.google.com/finance/info?q=NVDA";
	std::thread ticker1(updateTicker, testLink);
	ticker1.join();
	return 0;
}