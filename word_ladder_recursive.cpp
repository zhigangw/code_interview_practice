#include <string>
#include <unordered_set>
using namespace std;
int find_ladder(string begin_word, string end_word, unordered_set<string> word_dict) {
    if (!word_dict.contains(begin_word)) return 0;
    if (begin_word == end_word) return 1;
    int ladder_next = 0;
    word_dict.erase(begin_word);
    for (int i = 0; i < begin_word.size(); i++) {
        char c = begin_word[i];
        for (int j = 0; j < 26; j++) {
            if (c != j + 'a') {
                begin_word[i] = j + 'a';
                int sub_ladder = find_ladder(begin_word, end_word, word_dict);
                if (sub_ladder >0)
                {
                    if (ladder_next == 0) {
                        ladder_next = sub_ladder;
                    }
                    else {
                        ladder_next = min(ladder_next, sub_ladder);
                    }
                }
            }
        }
        begin_word[i] = c;
    }
    return ladder_next> 0 ? ladder_next + 1 : 0;
}
