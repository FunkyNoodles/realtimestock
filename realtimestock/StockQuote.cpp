#include "StockQuote.h"
#include <iostream>

#include <curl\curl.h>
#include <rapidjson\document.h>

using namespace rapidjson;
using namespace std;


StockQuote::StockQuote()
{
	CURL * curl = curl_easy_init();
	if (curl) {
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, "http://finance.google.com/finance/info?q=NVDA");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		readBuffer = readBuffer.substr(6, readBuffer.size() - 9);
		std::cout << readBuffer << std::endl;
		rapidjson::Document document;
		document.Parse(readBuffer.c_str());
		assert(document.IsObject());
		assert(document.HasMember("t"));
		assert(document["t"].IsString());
		std::cout << document["t"].GetString() << std::endl;
	}
}


StockQuote::~StockQuote()
{
}

size_t StockQuote::curlWriteCallback(void * contents, size_t size, size_t nmemb, void * userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
