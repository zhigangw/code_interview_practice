// InterviewPractice.cpp : Defines the entry point for the application.
//

#include "InterviewPractice.h"

using namespace std;

int main()
{
	int a[] = { 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7 };
	int index = find_in_rotated_array(a, sizeof(a) / sizeof(int), 2);
	cout << "Hello CMake: "<< index << endl;
	return 0;
}
