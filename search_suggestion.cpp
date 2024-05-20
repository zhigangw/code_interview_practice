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
	bool is_word;
};
class TrieTree {
public:
	TrieTree(vector<string> list_of_strings) {
		if (m_root == nullptr) {
			m_root = new TrieNode();
			m_root->c = 0; // root doesn't contain any charactor.
			m_root->is_word = false;
		}

		for (auto& word : list_of_strings) {
			insert_word(word);
		}
	}
	~TrieTree() {
		//traverse and delete TrieNodes
	}

	void insert_word(const string& word) {
		auto it = word.cbegin();
		TrieNode* q = m_root;
		TrieNode* p = q->children.contains(*it) ? p = q->children[*it] : nullptr;
		while (it != word.cend())
		{
			if (p == nullptr) {
				p = new TrieNode();
				p->c = *it;
				q->children[*it] = p;

			}
			q = p;
			it++;
			p = q->children.contains(*it) ? p = q->children[*it] : nullptr;
		}
		q->is_word = true;
	}

	void retrieve_words(string prefix, vector<string>& list_of_words) {
		if (m_root == nullptr) return;
		auto it = prefix.cbegin();
		TrieNode* p = m_root;
		while (it != prefix.cend() && p != nullptr && p->children.contains(*it)) {
			p = p->children[*it];
			it++;
		}
		if (it != prefix.cend()) {
			//there are still not matched chars, stop collecting words and return
			return;
		}
		collect_words(prefix, p, list_of_words);

	}
	void collect_words(string prefix, TrieNode* start, vector<string>& list_of_words) {
		if (start == nullptr) return;
		if (start->is_word) {
			list_of_words.push_back(prefix + start->c);
		}
		for (auto& node : start->children) {
			collect_words(prefix + start->c, node.second, list_of_words);
		}
	}
private:
	TrieNode* m_root = nullptr;
};
