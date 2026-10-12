#pragma once
#include <unordered_map>
#include <set>
#include <string>

class indexer 
{
private:
	std::unordered_map<std::string, std::set<std::string>> inverted_tree;
public:
	void update_tree(const std::string& base_url, const std::set<std::string>& tokens);
	const std::set<std::string>* search(const std::string& word);
};
