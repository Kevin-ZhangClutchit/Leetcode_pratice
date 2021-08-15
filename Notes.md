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

| i    | j    | x    | y    |
| ---- | ---- | ---- | ---- |
| 0    | 0    | 0    | 0    |
| 0    | 1    | 1    | 0    |
| 0    | 2    | 2    | 0    |
| 0    | 3    | 0    | 1    |
| 0    | 4    | 1    | 1    |
| 0    | 5    | 2    | 1    |
| 0    | 6    | 0    | 2    |
| 0    | 7    | 1    | 2    |
| 0    | 8    | 2    | 2    |

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