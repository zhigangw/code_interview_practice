// InterviewPractice.cpp : Defines the entry point for the application.
//

#include "InterviewPractice.h"

using namespace std;

int main()
{
	int a[] = { 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7 };
	//int index = find_in_rotated_array(a, sizeof(a) / sizeof(int), 2);
	quick_sorting(a, 0, sizeof(a) / sizeof(int) - 1);
	cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << a[6] << a[7] << a[8] << a[9] << a[10] << a[11] << endl;
	return 0;
}
