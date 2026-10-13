#pragma once
#include "indexer.hpp"
#include "crawler.hpp"

#include <thread>
#include <mutex>

class engine 
{
private:
	crawler _crawler;
	indexer _indexer;
	std::mutex lock;
public:
	void crawl();
	void search();

};
