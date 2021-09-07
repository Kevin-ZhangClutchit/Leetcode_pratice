#include <iostream>
#include <vector>
using namespace std;
//#704 Binary Search
int search(vector<int>& nums, int target) {
    if (nums.empty()){
        return -1;
    }
    size_t left=0;
    size_t right=nums.size()-1;
    while (left<=right){
        if (left==0&&right==0){
            return (nums[0]==target)?0:-1;
        }
        size_t mid=(left+right)/2;
        if (nums[mid]==target){
            return mid;
        }
        if (nums[mid]<target){
            left=mid+1;
        } else{
            right=(mid==0)?0:mid-1;
        }
    }
    return -1;
}

//#278 First Bad Version
static const int answer=4;
bool isBadVersion(int version){
    return version <= answer;
}//API abstarct

int firstBadVersion(int n) {
    int left=1,right=n;
    while (left<right){
        int mid=left+(right-left)/2;
        if (isBadVersion(mid)){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}
//#35 Search Insert Position
int searchInsert(vector<int>& nums, int target)  {
    if (nums.empty()){
        return 0;
    }
    size_t left=0;
    size_t right=nums.size()-1;
    while (left<=right){
        if (left==right){
            return (nums[left]<target)?int(left+1):int(left);
        }
        size_t mid=(left+right)/2;
        if (nums[mid]==target){
            return mid;
        }
        if (nums[mid]<target){
            left=mid+1;
        } else{
            right=mid;
        }
    }
    return nums.size();
}




int main() {
    vector<int> test={2,5};
    cout<<search(test,0)<<endl;
    cout<<firstBadVersion(1)<<endl;
    cout<<searchInsert(test,1)<<endl;
    return 0;
}
