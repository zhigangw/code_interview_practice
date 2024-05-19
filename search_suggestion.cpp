/*
* You are given an array of strings products and a string searchWord.
* Design a system that suggests at most three product names from products after each character of searchWord is typed.
* Suggested products should have common prefix with searchWord.
* If there are more than three products with a common prefix return the three lexicographically minimums products.
* Return a list of lists of the suggested products after each character of searchWord is typed.
*/

/*
* SOLUTION:
* build a trie tree to contain the strings
* traverse the trie tree to return the matched words.
* optimization: cache the top 10 words for each
*/
#include <map>
#include <vector>
#include <string>
using namespace std;
struct TrieNode {
	char c = 0;
	map<char, TrieNode*> children;
	vector<string> best_matches;
};
void insert_word_to_trie(TrieNode*& root, const string& word) {
	auto it = word.cbegin();
	if (root == nullptr) {
		root = new TrieNode();
		root->c = 0; // root doesn't contain any charactor.
		TrieNode* node = new TrieNode();
		node->c = *it;
		root->children[*it] = node;
	}

	TrieNode* q = root;
	TrieNode* p = q->children.contains(*it) ? p = q->children[*it] : nullptr;
	while (it != word.cend())
	{
		if (p == nullptr) {
			p = new TrieNode();
			p->c = *it;
			p->best_matches.push_back(word);
			q->children[*it] = p;

		}
		q = p;
		it++;
		p = q->children.contains(*it) ? p = q->children[*it] : nullptr;
	}
}
TrieNode* construct_trie(vector<string> list_of_strings) {
	TrieNode* root = nullptr;
	for (auto& word : list_of_strings) {
		insert_word_to_trie(root, word);
	}
	return root;
}

void retrieve_words_from_trie(string prefix, TrieNode* root, vector<string>& list_of_words) {
	if (root == nullptr) return;
	auto it = prefix.cbegin();
	TrieNode* p = root;
	while (it != prefix.cend() && p != nullptr && p->children.contains(*it)) {
		p = p->children[*it];
		it++;
	}
	if (it != prefix.cend()) {
		//there are still not matched chars, stop collecting words and return
		return;
	}
	if (p != nullptr) {
		for (const auto& lw : p->best_matches)
		{
			list_of_words.push_back(lw);
		}
	}
	else
	{
		list_of_words.push_back(prefix);
	}
}