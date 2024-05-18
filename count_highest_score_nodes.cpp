/*
There is a binary tree rooted at 0 consisting of n nodes. 
The nodes are labeled from 0 to n - 1. 
You are given a 0-indexed integer array parents representing the tree, where parents[i] is the parent of node i. 
Since node 0 is the root, parents[0] == -1.Each node has a score. To find the score of a node, consider if the node and the edges connected to it were removed. 
The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. 
The score of the node is the product of the sizes of all those subtrees.
Return the number of nodes that have the highest score.
*/

/*
* construct a binary tree array bta where the ith' left child node is in 2i + 1 and right node is in 2i + 2, and the value is the size of the (sub)tree rooted from the node.  
* caculate the score of each node by the following fomular
* (bta[0] - bta[i]) * bta[2*i + 1] * bta[2*i + 2]
*/