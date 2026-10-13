#pragma once
#include "indexer.hpp"
#include "crawler.hpp"

#include <thread>

class engine 
{
private:
	crawler _crawler;
	indexer _indexer;
	unsigned int count;
	std::mutex lock;
public:
	void crawl();
	void search();

};
