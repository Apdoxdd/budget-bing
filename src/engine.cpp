#pragma once
#include "engine.hpp"

#include <iostream>

void engine::crawl()
{
	while(true)
	{
		//std::cout<<"start response"<<std::endl;
		_crawler.set_response();
		_crawler.setup_xml();
		//std::cout<<"end response"<<std::endl;

		std::set<std::string> tokens;
		std::set<std::string> links;

		//std::cout<<"start tokens"<<std::endl;
		tokens = _crawler.extract_tokens();
		_indexer.update_tree(_crawler.base_url, tokens);
		//std::cout<<"end tokens"<<std::endl;

		//std::cout<<"start links"<<std::endl;
		links = _crawler.extract_links();
		links = _crawler.normalize_links(links);
		//std::cout<<"end links"<<std::endl;

		count++;


		_crawler.update_data_base(links);
		
	}
}

void engine::search()
{
	std::thread back_worker (&engine::crawl, this);
	back_worker.detach();
	std::cout<<"woker gone"<<std::endl;
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
			std::cout<<"#################################################"<<std::endl;
			std::cout<<"The results: "<<std::endl;
			for (auto& url : *results)
			{
				std::cout<<url<<std::endl;
			}
			std::cout<<"#################################################"<<std::endl;

		}
		std::cout<<count<<std::endl;
		std::cout<<"#################################################"<<std::endl;


	}


}




