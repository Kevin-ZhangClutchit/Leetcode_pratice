## Notes for Intro To Algorithm

[Problem Link](https://leetcode-cn.com/study-plan/algorithms/)

#### Day1

##### #704

Binary Search

Pay attention to the vector.size() return is size_t (unsigned long long int), so that when dealing with size==0, we should pay extra attention

##### #278

Binary Search

If mid is wrong, which means the first bad version happens in the left part (including middle).

If mid is right, which means the first bad version happens in the right part (excluding middle).

Update until left==right (which is when the dividing point).

Another attention: Rewrite: (left+right)/2 to left+(right-left)/2 to avoid exceed the upper bound of int.

##### #35

Similar to #704, just to modify when left==right, we need to compare whether the inserted value should be in the left or right of the value at the position.
