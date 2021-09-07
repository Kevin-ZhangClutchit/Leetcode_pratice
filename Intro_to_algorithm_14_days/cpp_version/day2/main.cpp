#include <iostream>
#include <vector>

using namespace std;
//#977 Squares of a Sorted Array
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> answer;
    if (nums.empty()){return answer;}
    if (nums.size()==1){
        answer.emplace_back(nums[0]*nums[0]);
        return answer;
    }
    else{
        answer.resize(nums.size());
        size_t i=0,j=nums.size()-1,k=nums.size()-1;
        while (i<=j){
            if (abs(nums[i])>=abs(nums[j])){
                answer[k]=nums[i]*nums[i];
                i++;
                k--;
            }else{
                answer[k]=nums[j]*nums[j];
                j--;
                k--;
            }
        }
        return answer;

    }

}
//#189 Rotate Array
// Triple Reverse~
void reverse(vector<int>& nums,size_t begin,size_t end){
    if (nums.empty()||nums.size()==1||begin==end){
        return;
    } else{
        while (begin<=end){
            swap(nums[begin],nums[end]);
            begin++;
            end--;
        }

    }
}
void rotate(vector<int>& nums,int k){
    k%=nums.size();
    if (k==0||nums.empty()||nums.size()==1){
        return;
    }
    reverse(nums,0,nums.size()-1);
    reverse(nums,0,k-1);
    reverse(nums,k,nums.size()-1);
}

//insert at head version
void rotate2(vector<int>& nums, int k) {
    k%=nums.size();
    if (k==0||nums.empty()||nums.size()==1){
        return;
    }
    while (k>0){
        nums.insert(nums.begin(),nums.back());
        nums.pop_back();
        k--;
    }
}

int main() {
    vector<int> nums={1,2};
    sortedSquares(nums);
    rotate(nums,2);
    return 0;
}
