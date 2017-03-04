#include "StockQuote.h"
#include <iostream>

#include <curl\curl.h>

using namespace rapidjson;
using namespace std;


StockQuote::StockQuote()
{
	timeSeries = new TimeSeries();
	
}


StockQuote::~StockQuote()
{
	delete timeSeries;
}

std::string StockQuote::getNewStockData(std::string url)
{
	CURL * curl = curl_easy_init();
	std::string stockData;
	if (curl) {
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stockData);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		stockData = stockData.substr(6, stockData.size() - 9);
		return stockData;
	}
	return NULL;
}

double StockQuote::getPrice(std::string stockData)
{
	rapidjson::Document document;
	document.Parse(stockData.c_str());
	assert(document.IsObject());
	assert(document.HasMember("l"));
	assert(document["l"].IsString());
	return stod(document["l"].GetString());
}

std::string StockQuote::getId(std::string stockData)
{
	rapidjson::Document document;
	document.Parse(stockData.c_str());
	assert(document.IsObject());
	assert(document.HasMember("id"));
	assert(document["id"].IsString());
	return document["id"].GetString();
}

std::string StockQuote::getExchange(std::string stockData)
{
	rapidjson::Document document;
	document.Parse(stockData.c_str());
	assert(document.IsObject());
	assert(document.HasMember("e"));
	assert(document["e"].IsString());
	return document["e"].GetString();
}

double StockQuote::getChange(std::string stockData)
{
	rapidjson::Document document;
	document.Parse(stockData.c_str());
	assert(document.IsObject());
	assert(document.HasMember("c"));
	assert(document["c"].IsString());
	return stod(document["c"].GetString());
}

double StockQuote::getPercentChange(std::string stockData)
{
	rapidjson::Document document;
	document.Parse(stockData.c_str());
	assert(document.IsObject());
	assert(document.HasMember("cp"));
	assert(document["cp"].IsString());
	return stod(document["cp"].GetString());
}

size_t StockQuote::curlWriteCallback(void * contents, size_t size, size_t nmemb, void * userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
