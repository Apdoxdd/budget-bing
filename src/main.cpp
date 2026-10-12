#include "crawler.hpp"

#include <curl/curl.h>
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>

int main()
{
	crawler c1;
	c1.set_response();
	c1.setup_xml();
	std::set<std::string> links;
	links = c1.extract_links();
	c1.update_data_base(links);

}

