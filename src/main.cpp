#include "crawler.hpp"
#include "indexer.hpp"
#include "engine.hpp"

#include <curl/curl.h>
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>

int main()
{
	engine _engine;
	_engine.search();
}

