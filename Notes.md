Notes for Leetcode

#### Day1

##### #217

Property of Hash table. O(n) for one traversal of the input and O(1) for insert and search in hash table.

One element is not in hash table then insert it. If it has been in then return true. After one traversal, return false.

##### #53

Dynamic Programming.

Hold two flag variables: partial_sum for holding the current sum of a sequence and prev_best for holding the previous max sum.

During traversal, when we have a positive partial sum, we can ensure it is the largest partial sum of the previous sub sequence(which means partial_sum(before add)== prev_best).

When we have a negative or zero partial sum, which means the previous sequence doesn't contribute to a larger partial sum. So we update the beginning of the subsequence to current one.

#### Day2

##### #1

Property of Hash table.(My method)

Previous I think a 2*O(n) algorithm but a better way is in O(n)  hinted by comments.

During the traversal, we keep find whether (sum - current) has been stored in a hash table(utilize the O(1) search of hash table), if not, insert it to the hash table as (number,location) pair(using number as key to search for location). If yes, push current location and hashtable[sum-current value] to the answer vector.(utilize O(1) search and get of hash table).

##### #88

From back to front insertion due to the empty space exists at the last of nums1 vector.

Utilize a trick of shift from number of elements remaining and position in one variable.(But this is not appropriate need to be revised)

Each time, at the current last position, insert the largest element of nums1 and nums2 last as they have been already sorted. Somehow like a reverse version of the merge in the merge sort.

##### #283

cpp 17(?) new feature stable_sort with personalized comp.

It some how likes a merge sort with specialized comparison requirements to make 0 as the largest and others are all equal.

std::stable_sort is like merge sort provided by cpp17 and rewrite the comp to meet the requirements (rewrite of comp practice in VE281 ww)

#### Day3

##### #350

Hashtable

First, to save memory as Hashtable is quite space consuming. We store the one with smaller size to the hash table. In the hashtable, <key,value> is like <number,frequency>, the first time we insert one number, we set the value to one, other times we increase it.

Then traversal the other vector, and update the frequency and push the one exists in both vectors to the answer vector.

#121

Dynamic Programming

maintain two store variables: (1) max profit in the previous days (2) minimum buying prices in the previous days

Each time, first updates (2) and then compare (sell today - (2)) with (1) and updates (1) if necessary.

#### Day4

##### #566

Treat the matrix as an array then arrange the array into m\*n and r\*c matrixs

##### #118

Dynamic Programming

store the before rows result and what we need to do is like fib that we add the left and right predecessor of current position.

##### #1170

How to calculate frequency: utilize the sort function provided by cpp STL which is also available for string then count the first n (duplicate) elements number.

The process of searching is like counting sort. We first traversal the words vector to count how many words are of certain frequencies and then based on counting sort, we set the counting vector to be the number of words with frequency less or equal to given frequency. To transfer it to words with f(queries[i])<f(w), we just need to calculate (words.size()-current value).

Note 11 in my code is to ensure that 1-10 (length limitations given by the problem description) frequency can be reached when traversal and without index issues.

#### Day5

##### #36

Dynamic Programming(?)

utilize property of hash set (no duplicate and O(1) search)

traversal and check. Main issue here is the 9x9 grid check, with in one i and 0-9 j, we have to traversal one certain 9x9 grid. We derive following table:

| i | j | x | y |
| - | - | - | - |
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 0 | 2 | 2 | 0 |
| 0 | 3 | 0 | 1 |
| 0 | 4 | 1 | 1 |
| 0 | 5 | 2 | 1 |
| 0 | 6 | 0 | 2 |
| 0 | 7 | 1 | 2 |
| 0 | 8 | 2 | 2 |

With derive equation:

```c++
x=(i%3)*3+j%3;//(which level in the three left to right levels)+(which level in the three small levels in one big level)
y=(i/3)*3+j/3;//(which level in the three up to down levels)+(which level in the three small levels in one big level)
```

![9x9GridDerive](https://github.com/Kevin-ZhangClutchit/Leetcode_pratice/raw/main/day5/9x9GridDerive.png)

##### #73

O(M+N) space complexity method: hold an array with m+n size to store whether ith row/column needs to be set to zero.

O(1) space complexity method: first check whether the first row and column need to be set to zero. Then use the first row and column as the signal array in the O(M+N) method.

#### Day6

##### #387

A relative poor algorithm.

Use map to store the <char, location> information and in the first traversal, when first meet one char, store its first appear location and if met more than once, update the location information to -1 to signal it as invalid.

Then traversal the map by dynamic programming to decide the smallest location.

##### #383

Hash table.

Store <char,appear_times> information into hashtable. When traversal ransomNote, update the appear_times.

##### #242

Rely on c++ sort to sort the two strings respectively and then compare whether they are equal.

#### Day7

Mainly about Linked list. Not too many notes......

##### #141

use a hash set(store node as value is not unique) to see whether a node has been visited twice.

##### #21 && #203

Recursion

#203  notice to avoid memory leak(Otherwise it can be written in the same form as #21)

#### Day8

still Linked list......

##### #206

recursion reverse: each time reverse the direction of two connected edges

##### #83

Pay attention to the connection of the prev nodes of the deleted nodes and next nodes of the deleted nodes.(Order before delete node)

#### Day9

##### #20

Stack, as what we need to compare is the last input parenthesis, LIFO, which is the property of stack.

Besides, in implementation, to cut off the number of the required if statements, we take advantage of the property of ascii "{"-"}" and "["-"]"==2.

##### #232

Use stack to implement queue.

(FILO)+(LIFO)=(FIFO)

Maintain a push_stack and a pop_stack, unless the pop_stack is empty, we just push the elements into push_stack which indicates their reverse push-in order.

#### Day10

##### #94 #144 #145

tree traversal. Not too much to say about algorithm. Pay attention to the implementation of passing reference.

#### Day11

##### #102

Example of BFS in VE281 courses. This problem requires one extra requirements of identify which nodes in which level. A trivial idea is to record the size of the queue (the number of nodes after pushing all the children nodes in the previous level)

##### #104

Recursion. Basic binary tree recursion problem. Write a helper to update the depth.

##### #101

Recursion.

Return condition: root node is null pointer. || left node and right node is null pointer.

Repeated steps:
Judge following situation:

1. whether the nodes existence are symmetric
2. whether the two nodes' value are equivalent
3. whether the LL(left nodes in the left subtree) and RR nodes are symmetric
4. whether the LR and RL nodes are symmetric

#### Day12

##### #226

Recursion.
Return condition: When the input node is empty node.
Repeated steps: swap the left and the right children

##### #112

Recursion.
Return condition: When the input node is empty node or we reach the left node.
Repeated steps:

1. Subtract current node value from the path sum.
2. whether the left subtree has the new certain path sum
3. whether the right subtree has the new certain path sum

#### Day13

##### #700 #701

Recursion and the basic concept of BST(Binary Search Tree).

#### Day14

##### #98

Recursion and property of the pre-order traversal of BST.

As learned in VE281, the pre-order traversal of BST is a sequence of number in ascending order which means that during the traversal, if the value of a previous node is larger than the value in the current node, it is not a valid BST.

##### #653

Similar to #1, what is different is that we need to search left and right subtree. (In-order depth first search) As a result, iteration there, recursion here.

##### #235

Recursion.
Return condition: When the input node is empty node or we reach the left node.
1. The root node of the tree is empty.
2. The root node is one of the node in the comparison.
3. Two nodes are in the different subtree of current root nodes.

Repeated steps: Find which of the subtree two nodes lies in and update the root node.
