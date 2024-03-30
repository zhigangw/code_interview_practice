// InterviewPractice.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
int binary_search(int* array, int size, int value);
int find_in_rotated_array(int* a, int size, int value);
int subarrays(int* a, int size, int k);
int subarry_slide_window(int* a, int size, int k);
void quick_sorting(int* a, int low, int high);
int find_kth_pq(int* a, int n, int k);
int find_kth_smallest(int* a, int n, int k);
void find_closest_kth(int* a, int n, int* output, int k, int x);
bool generate_permutation(int* a, int n);