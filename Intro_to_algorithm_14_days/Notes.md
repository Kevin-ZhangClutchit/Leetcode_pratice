## Notes for Intro To Algorithm

[Problem Link](https://leetcode-cn.com/study-plan/algorithms/)

#### Day1

##### #704 Binary Search

Binary Search

Pay attention to the vector.size() return is size_t (unsigned long long int), so that when dealing with size==0, we should pay extra attention

##### #278 First Bad Version

Binary Search

If mid is wrong, which means the first bad version happens in the left part (including middle).

If mid is right, which means the first bad version happens in the right part (excluding middle).

Update until left==right (which is when the dividing point).

Another attention: Rewrite: (left+right)/2 to left+(right-left)/2 to avoid exceed the upper bound of int.

##### #35 Search Insert Position

Similar to #704, just to modify when left==right, we need to compare whether the inserted value should be in the left or right of the value at the position.

#### Day2

##### #977 Squares of a Sorted Array

A problem occurred in VE281 21SU. From two end of the list (largest and smallest), decide which one is of greater abstract value, push it to the end of the answer vector.(By using vector.resize() to first create space and then assign like an array)

##### #189 Rotate Array

simple return situation: reverse times k = 0, nums vector empty or size ==1

Also, to save time, k%=nums.size() is applied to ensure that we at most reverse the vector vector.size()-1 times.

Besides, as vector is treated with size_t. Pay attention to its unsigned property when dealing with size_t - 1.

###### Method 1: Insert at the head

Meet with time exceed issues on Leetcode.

Each time, insert the last elements in the vector to the head of the vector. Then Remove it and update k.

###### Method 2: Triple Reverse

Learn from comments.

For example, 1 2 3 4 5 with k=3, results are 3 4 5 1 2.

It can be treat as a 3-times reverse:

- First, reverse the whole vector to 5 4 3 2 1.
- Then, two reverses are carried out on the sub array 5 4 3 and 2 1.

So the algorithm is as:

```C++
Reverse(vec,0,vec.size()-1);
Reverse(vec,0,k-1);//After k reverses, k new elements exist at the beginning.
Reverse(vec,k,vec.size()-1);
```

#### Day3

##### #283 Move Zeroes

A duplicate problem, notes seen the link below:

[Notes for Move Zeroes](https://github.com/Kevin-ZhangClutchit/Leetcode_pratice/blob/main/Data_structure_basic_14_days/Notes.md#283)

##### #167 Two Sum II - Input array is sorted

Double pointers

Basic idea:

- As the array is sorted, we hold a head pointer (the smallest element to be selected) and a tail pointer(the biggest element to be selected).
- If the head value + tail value > target, which means the tail value is too large, we decrease it.
- If the head value + tail value < target, which means the head value is too small, we increase it.
- If the head value + tail value == target (as ensured by the problem), we insert head index + 1 and tail index +1 to the vector.

#### Day4

##### #344 Reverse String

Swap according to the size is whether an odd or even number.

##### #557 Reverse Words in a String III

detect space then #344

#### Day5

Both fast pointers and slow pointers in linked list.

##### #876 Middle of the Linked List

An easier version of #19, set the ahead_steps to 1 and no need of slow_pre (as no deletion).

##### #19 Remove Nth Node From End of List

We hold 3 pointers:

- slow_pre: the pointer before the slow pointers (to achieve delete) (Initial nullptr)
- slow: the pointer to be deleted (Initial head)
- fast: the pointer used to signal the end of the linked list (Initial head)

Set the ahead_steps to be equal to n and update fast pointers to be ahead of such steps to slow.

While fast pointers is not nullptr, update slow_pre, slow and fast.

When jumping out of the pre loop, if slow_pre is nullptr which signals the head is need to be deleted, we set head=head->next and delete slow (which is past head), else we set slow_pre->next=slow->next and delete slow.

#### Day6

##### #3 Longest Substring Without Repeating Characters

Sliding windows. Hold two pointers, left and right (Both initially at the begin).

- While right doesn't reach the end of the string, update the right until meet a substring with repeating character.
- Update the best result so far.
- Increase the left pointer and repeat the loops.

##### #567 Permutation in String

Sliding windows. Hold two unorder_maps: one is to store the information of s1, the other is update during each windows to judge whether permutation exists.

Set the left and right to be of a distance as the size of s1.

Each time, compare whether the substring given by the [left,right] is of the same characters composition as s1. Then increase both left and right until the right reaches the end of the string.

#### Day7

##### #733 Flood Fill

Depth First Search.

If current_color == new_color, end the loop to avoid no return.

Else, starting from the target point, judge whether the boundary has been reached && whether the adjacent grid is of different colors.

##### #695 Max Area of Island

Depth First Search.

Traversal the grid, once meet an island, update all the islands grid reached by DFS to 0 and calculate the area.

#### Day8

##### #617 Merge Two Binary Trees

Recursion.(DFS)

Merge the root node and then merge the left node, right node respectively.

##### #116 Populating Next Right Pointers in Each Node

As initially all next pointers are nullptr, we don't need to consider the next node of the right-most nodes in every level. Besides, as it is a perfect binary tree, all nodes can be connected together through its parent-level nodes(excluding the root node).

* Connect two sub-nodes.
* Connect right sub-node to the sibling's left node if necessary.
* Connect left subtree.
* Connect right subtree.

#### Day9

##### #542 01 Matrix

BFS with multi-source, somehow likes #102.

We record the one with initial value 0 as level 0 nodes then detect whether their children (adjacent nodes in four directions) are 1, if so update its value as 0 and set it to level 1. Repeat such steps until the queue is empty.

##### #994 Rotting Oranges

Little bit complex version of #542.

In the first traversal to record the source (rotten oranges), we also record the number of fresh oranges as long as all fresh oranges are rotten, we return. Besides this, it is the same as #542.
