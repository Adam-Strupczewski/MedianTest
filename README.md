# MedianTest

Insertsort implementation using sorted array:
* Find insertion place in O(logN)
* Search median time O(1)
* Inserting new element O(N)
* Total complexity : O(N)
* Total complexity for N elements : O(N)^2

Implementation using 2 unbalanced binary search trees:
* Find insertion place in O(logN)
* Search median time O(logN), worst case O(N)
* Inserting new element log(N), worst case O(N)
* Total complexity : O(logN), worst case O(N)
* Total complexity for N elements : O(NlogN), worst case O(N)^2

Implementation using 2 heaps:
* Find insertion place in O(logN)
* Search median time O(logN)
* Inserting new element log(N)
* Total complexity : O(logN)
* Total complexity for N elements : O(NlogN)

Notes.
- Implementation with a balanced binary tree could be equivalent to 2 heaps in time complexity, but much more complicated.
- If median is not required for every input value, an algorithm running quickselect (O(N)) whenever median is needed might be faster (K*N complexity, where K is number of median reads, so faster if K < logN).
- If there is a small range of incoming numbers, a simple histogram with counts in each cell might be most efficient (constant retrieval & insertion time depending on size).
- If there are more incoming numbers than memory available, need to create histogram and possibly use approximate approach with quantization.