/*
* we will scan the string first to collect the farest left and farest right for each letter. O(n)
* we will then scan the range and try to merge them by the following rule:
* 1) If the the range is within the previous one, merge it into.
* 2) If the range is crossing with the previous one, merge two using the mininum of the farest left and the maximum of the farest right.
* 3) If the range is seprate from the previous one, log the previous one as a group. Start a new one.
* 4) an optimization: we in fact only need record the farest right value of the range when we do the first scaning. And when we do the second scaning,
*    we can just let the farest left start from zero, and the start with the farest right of the previous range + 1 when we do the seperation.
* 5) futhur optimization: we can just scan the hash map and see who is impacting, the one with farest right. We do the seperation when we meet the farest right.
*/


#include <string>
#include <vector>
using namespace std;
void partition_label(string s, vector<int>& output) {
    /*give they are lower case chars, we can use using a int array with size of 26*/
    int a[26] = { 0 };
    for (int i = 0; i < s.size(); i++)
    {
        a[s.c_str()[i] - 'a'] = i;
    }
    int far_left = 0;
    int far_right = 0;
    for (int i = 0; i < s.size(); i++) {
        if (far_right < a[s[i] - 'a']) {
            far_right = a[s[i] - 'a'];
        }
        if (far_right == i) {
            /*log a group*/
            output.push_back(far_right - far_left + 1);
            far_left = far_right + 1;
        }
    }
}

/*
*TEST1:
* INPUT: 'ababcbacadefegdehijhklij'
* OUTPUT: [9,]
*/