/*
*word ladder
* we will use BFS to travese the possible paths and see if we can find one from beginword to endword
*/
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int word_ladder(string begin_word, string end_word, vector<string>& word_list) {
    unordered_set<string> word_dict(word_list.begin(), word_list.end()); // remember the word to visit
    queue<string> to_visit_queue;
    string current_word;
    to_visit_queue.push(begin_word);
    int ladder = 1;
    while (!to_visit_queue.empty()) {
        current_word = to_visit_queue.front();
        to_visit_queue.pop();
        if (current_word == end_word) {
            return ladder;
        }
        word_dict.erase(current_word); // remove the current word from the dict so we will not visit it again in future
        //enumerate the possible words to go
        for (int i = 0; i < current_word.length(); i++) {
            char c = current_word[i];
            for (int j = 0; j < 26; j++) {
                if (c != j + 'a') {
                    current_word[i] = j + 'a';
                    if (word_dict.find(current_word) != word_dict.end()) { // we find the variant in the word dict
                        to_visit_queue.push(current_word); //push into the queue
                    }
                }
            }
            current_word[i] = c;
        }
        ladder++;
    }
    return 0;
}