#include "indexer.hpp"

void indexer::update_tree(const std::string& base_url, const std::set<std::string>& tokens)
{
	for (const auto& token : tokens)
	{
		this->inverted_tree[token].insert(base_url);
	}
}

const std::set<std::string>*indexer::search(const std::string& word)
{
	auto it = inverted_tree.find(word);
	return (it != inverted_tree.end())? &it->second : nullptr;
}
