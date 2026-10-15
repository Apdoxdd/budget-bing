#pragma once
#include "indexer.hpp"
#include "crawler.hpp"
#include <atomic>

#include <thread>

class engine 
{
private:
	crawler _crawler;
	indexer _indexer;
	std::atomic<unsigned int> count;
	std::mutex lock;
public:
	void crawl();
	void search();

};
