#include "crawler.hpp"
#include "indexer.hpp"

#include <curl/curl.h>
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>

int main()
{
	crawler c1;
	c1.set_response();
	c1.setup_xml();
	indexer i1;

	std::set<std::string> tokens;
	std::set<std::string> links;

	tokens = c1.extract_tokens();
	i1.update_tree(c1.base_url, tokens);
	auto urls = i1.search("you"); // pointer to set
				      //
	if(urls == nullptr)
		std::cout<<"No results found"<<std::endl;
	else
	{
		std::cout<<"links containg the word:"<<std::endl;
		for (auto url : *urls)
		{
			std::cout<<url<<std::endl;
		}
	}

	links = c1.extract_links();
	links = c1.normalize_links(links);
	c1.update_data_base(links);

}

