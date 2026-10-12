#pragma once
#include <curl/curl.h>
#include <fstream>
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>
#include <set>
#include <iostream>

class crawler 
{
private:
	CURL *handle;
	std::fstream data_base;
	std::string response;	
	std::string base_url;
	std::set<std::string> seenLinks;
	htmlDocPtr doc;
	xmlXPathContextPtr context;
	std::streampos pos;

public:
	crawler();
	~crawler();
	void send_request(std::string& url);
	bool set_response();
	std::set<std::string>extract_links();
	bool setup_xml();
	void update_data_base(std::set<std::string>& links);


};

