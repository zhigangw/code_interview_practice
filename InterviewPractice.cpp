// InterviewPractice.cpp : Defines the entry point for the application.
//

#include "InterviewPractice.h"

using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//int index = find_in_rotated_array(a, sizeof(a) / sizeof(int), 2);
	// int o[] = {0,0,0,0,0};
	// find_closest_kth(a, sizeof(a) / sizeof(int),o, 5, 7);
	const char* parttern = "i27n";
	const char* source = "iasfasdfasdfasdfasdfasdfsadfn";
	find_pattern_i18n(parttern, 4, source, 29);
	cout << a[7] << a[8] << a[9] << a[10] << a[11] << endl;
	return 0;
}
