#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
//#1
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> hash;
    vector<int> answer;
    for (int i = 0; i < nums.size(); ++i) {
        if (hash.find(target-nums[i])==hash.end()){
            hash[nums[i]]=i;
            continue;
        }else{
            answer.emplace_back(hash[target-nums[i]]);
            answer.emplace_back(i);
            return answer;
        }

    }

    return answer;

}
//#88
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n==0){return;}
    if (m==0){nums1=nums2;return;}
    int last=m+n-1;
    m--;n--;//shift m,n to the num of numbers in the vector to the pos
    while (m>=0 && n>=0){
        nums1[last]=max(nums1[m],nums2[n]);
        if (nums1[m]>=nums2[n]){
            m--;
        } else{n--;}
        last--;
    }
    m++;n++;//shift back from pos to num
    if (m==0){
        for (int i = 0; i < n; ++i) {
            nums1[i]=nums2[i];
        }
        return;
    }
}
//#283
static bool compare (const int &a, const int &b){
    if (b==0){return true;}
    else {return false;}
}

void moveZeroes(vector<int>& nums) {
    std::stable_sort(nums.begin(),nums.end(),compare);
}



int main() {
    vector<int> test;
    test.emplace_back(3);
    test.emplace_back(2);
    test.emplace_back(4);
    vector<int> answer;
    answer=twoSum(test,6);
    for (int i : answer) {
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> nums1;
    vector<int> nums2;
    nums1.emplace_back(2);
    nums1.emplace_back(0);
    nums2.emplace_back(1);
    merge(nums1,1,nums2,1);
    for (int i : nums1) {
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> test2;
    test2.emplace_back(0);
    test2.emplace_back(1);
    test2.emplace_back(0);
    test2.emplace_back(3);
    test2.emplace_back(12);
    moveZeroes(test2);
    for (int i : test2) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
