// InterviewPractice.cpp : Defines the entry point for the application.
//

#include "InterviewPractice.h"

using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//int index = find_in_rotated_array(a, sizeof(a) / sizeof(int), 2);
	int o[] = {0,0,0,0,0};
	find_closest_kth(a, sizeof(a) / sizeof(int) - 1,o, 5, 7);
	cout << o[0] << o[1] << o[2] << o[3] << o[4] << endl;
	return 0;
}
