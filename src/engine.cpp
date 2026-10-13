#pragma once
#include "engine.hpp"

#include <iostream>

void engine::crawl()
{
	while(true)
	{
		_crawler.set_response();
		_crawler.setup_xml();

		std::set<std::string> tokens;
		std::set<std::string> links;

		tokens = _crawler.extract_tokens();
		_indexer.update_tree(_crawler.base_url, tokens);

		links = _crawler.extract_links();
		links = _crawler.normalize_links(links);

		_crawler.update_data_base(links);
	}
}

void engine::search()
{
	std::thread back_worker (&engine::crawl, this);
	back_worker.detach();
	while(true)
	{
		std::string keyword {};
		std::cout<<"Enter the keyword to search for:"<<std::endl;
		std::cin>>keyword;
		
		auto results = _indexer.search(keyword);

		if(results == nullptr)
		{
			std::cout<<"No results"<<std::endl;
		}
		else 
		{
			std::cout<<"The results: "<<std::endl;
			for (auto& url : *results)
			{
				std::cout<<url<<std::endl;
			}

		}


	}


}




