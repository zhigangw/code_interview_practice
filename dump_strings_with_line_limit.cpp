/*
* print text within 25 chars per line
* questions:
* what is the input? stringstream?
* what is the output? string list? or just output to console.
* the length 25, including the end of the string and the /r/l or not?
* are those charactors ascII(a byte) or unicode(two bytes)?
* what if there are more spaces remaining?
* what if there are words which is longer than 25?
*/

#include <sstream>
#include <string>
#include <list>
using namespace std;
const int c_length_limit = 25;
void print_with_length_limit(stringstream& ss, list<string>& sl) {
    /*
    * we will have a string list, where we will place our strings for a line
    * we collect from string stream one by one while counting the number of the words and the charactors
    * We will use a variable to remember the length of the remaining spaces. It starts from 25.
    * Once we collect one word, we substract the length of the word plus one for the space from the remaining space
    * When we find out the remaining space is not enough to contain coming word, that means the current line is full.
    * we will dump the strings we collect into a string with the spaces distributed evenly or leave it as it is for the last line.
    * we will repeat above.
    */
    string word;
    int remaining_space = c_length_limit;
    list<string> container;
    while (getline(ss, word, ' ')) {
        bool placed = false;
        if (remaining_space >= word.length()) {
            if (container.size() == 0) //for the first word, we will just put it in
            {
                //need to check the length of the word is more than remaining_space even for the first word.
                container.push_back(word);
                remaining_space -= (int)word.length();
                placed = true;
            }
            else { //for the words after the first, we will also need to check if there is a space for the whitespace
                if (remaining_space > word.length())
                {
                    container.push_back(word);
                    remaining_space -= (int)(word.length() + 1);
                    placed = true;
                }
            }
        }
        if (!placed) { // no enough space for the current line. we need to dump the collected strings, and start for a new line
            string dump;
            //caculate the number of white spaces bewteen each word
            int num_whitespaces = (int)(remaining_space / container.size());
            int extra_whitespaces = (int)(remaining_space % container.size());
            for (auto i = container.begin(); i != container.end(); i++) {
                dump += *i;
                for (int nw = 0; nw < num_whitespaces; nw++) dump += ' ';
                if (extra_whitespaces > 0) {
                    dump += ' ';
                    extra_whitespaces--;
                }
            }
            sl.push_back(dump);
            //reset the container and the counters.
            container.clear();
            //need to check the length of the word is more than remaining_space even for the first word.
            remaining_space = c_length_limit;
            container.push_back(dump);
            remaining_space -= (int)(word.length());
        }
    }
    //handle the list line. no need to distribute the space evently, but just dump all the collected words.
    string dump;
    for (auto i = container.begin(); i != container.end(); i++) {
        dump += *i;
        dump += ' ';
    }
    sl.push_back(dump);
}