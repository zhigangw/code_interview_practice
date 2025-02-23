#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(string s) {
	int left = 0;
	auto right = s.size() - 1;

	if (left >= right) return false;
	int deleted = 0;
	while (left < right && deleted <= 1) {
		if (s[left] != s[right]) {//we try to delete an unmatched one by ignore it
			//decide which one is to be deleted
			if (left < right && s[left + 1] == s[right]) {
				left++;
				deleted++;
			}
			else if (left > right && s[left] == s[right - 1]) {
				right--;
				deleted++;
			}
			else {
				deleted += 2; //both condition checks failed. we have to delete two at least. 
				break;
			}
		}

		if (s[left] == s[right]) {
			left--;
			right++;
		}
	}
	return deleted <= 1;
}
