# CMakeList.txt : CMake project for InterviewPractice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("InterviewPractice")

# Add source to this project's executable.
add_executable (
	InterviewPractice 
	"InterviewPractice.cpp" 
	"InterviewPractice.h" 
	"BinarySearch.cpp"  
	"BinarySearchRotatedArray.cpp" 
	"subarray_less_than_k.cpp" 
	"subarray_less_than_k_slide_window.cpp" 
	"quick_sort.cpp" 
	"city.cpp" 
	"i18n.cpp" 
	"kth.cpp" 
	"lowestcommonancestor.cpp" 
	"parentthese.cpp" 
	"tree-to-list.cpp" 
	"vacation.cpp" 
	"tree_depth.cpp" 
	"kth.cpp" 
	"kth_pq.cpp" 
	"find_kth_closest.cpp"
 "GeneratePermutation.cpp" "mean_of_two_sorted.cpp" "longest_palindrom.cpp" "longest_common_substrings.cpp" "max_subarray.cpp" "merge_intervals.cpp" "nested_sum_weight.cpp" "max_stack.cpp" "hho_barriar.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET InterviewPractice PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
