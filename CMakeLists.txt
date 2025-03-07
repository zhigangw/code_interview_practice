﻿# CMakeList.txt : CMake project for InterviewPractice, include source and define
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
	"binary_search.cpp"  
	"binary_search_rotated_array.cpp" 
	"subarray_less_than_k.cpp" 
	"subarray_less_than_k_slide_window.cpp" 
	"quick_sort.cpp" 
	"city.cpp" 
	"i18n.cpp" 
	"kth.cpp" 
	"lowest_common_ancestor.cpp" 
	"parentthese.cpp" 
	"tree_to_list.cpp" 
	"vacation.cpp" 
	"tree_depth.cpp" 
	"kth.cpp" 
	"kth_pq.cpp" 
	"find_kth_closest.cpp"
 "generate_permutation.cpp" 
 "mean_of_two_sorted.cpp" 
 "longest_palindrom.cpp" 
 "longest_common_substrings.cpp" 
 "max_subarray.cpp" 
 "merge_intervals.cpp" 
 "nested_sum_weight.cpp" 
 "max_stack.cpp" 
 "hho_barriar.cpp" 
 "closest_k_bst.cpp" 
 "execlusive_function_time.cpp" 
 "bst_serialization.cpp" 
 "valid_graph_tree.cpp" 
 "all_o1.cpp" 
 "max_points.cpp" 
 "num_of_islands.cpp" 
 "partition_label.cpp" 
 "dump_strings_with_line_limit.cpp" 
 "random_get.cpp" 
 "max_product.cpp" 
 "word_ladder_queue.cpp" 
 "word_ladder_recursive.cpp" 
 "house_robber.cpp" 
 "authentication_manager.cpp"
 "isIsomorphic.cpp" "min_types.cpp" "max_stack_sorted_map.cpp" "find_pivot.cpp" "closest_k_bst_list.cpp" "valid_triangles.cpp" "celebrity.cpp" "lowest_common_ancestor_bst.cpp" "min_steps_to_make_angram.cpp" "search_suggestion.cpp" "one_swap_to_equal.cpp" "design_file_system.cpp" "wall_and_gate.cpp" "nearest_x_y.cpp" "sub_island.cpp" "jump_game_gas.cpp" "jump_game_mini_steps.cpp" "course_schedule.cpp" "basic_caculator.cpp" "eat_banana.cpp" "single_thread_cpu.cpp" "IsPalindrome.cpp" "merge_sorted.cpp" "valid_abbr.cpp" "find_diameter.cpp" "traverse_binary_tree_in_vertical_order.cpp" "remove_minimal_parenthesis.cpp" "lowest_common_ancestor_3.cpp" "kth_largest_element.cpp" "ocean_view.cpp" "k_sum.cpp" "deep_copy_linkedlist.cpp" "peak_element.cpp" "find_lca.cpp" "pick_random.cpp" "binary_tree_diameter.cpp" "valid_path.cpp" "dot_product.cpp" "top_k_frequent.cpp" "custom_sort.cpp" "range_sum.cpp" "max_ones.cpp" "max_profit.cpp" "sum_root.cpp" "pow.cpp" "lru_cache.cpp" "k_closest_points.cpp" "tree_to_list2.cpp" "collect_intervals.cpp" "shortest_path_binary_graph.cpp" "max_swap.cpp" "merge_intervals2.cpp" "two_sum.cpp" "remove_nth.cpp" "group_shifted.cpp" "closest_in_bst.cpp" "is_subsequence.cpp" "right_view.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET InterviewPractice PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
