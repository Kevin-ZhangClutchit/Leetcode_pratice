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

