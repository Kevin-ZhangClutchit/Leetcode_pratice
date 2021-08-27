#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//#217
bool containsDuplicate(vector<int>& nums){
    std::unordered_map<int,int> hash;
    for (int i = 0; i < nums.size(); ++i) {
        if (hash.find(nums[i])==hash.end()){
            hash[nums[i]]=i;
        }else{
            return true;
            }
        }
    return false;
}
//#53
int maxSubArray2(vector<int>& nums) {
    int partial_sum=0;
    int prev_best=0;
    if (nums.size()==1){return nums[0];}
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i]>=0){
            partial_sum+=nums[i];
        }else{
            if (i!=nums.size()-1&&nums[i]+nums[i+1]>0&&partial_sum+nums[i]>0){
                partial_sum+=nums[i];
            }else {
                if (partial_sum>prev_best){
                    prev_best=partial_sum;
                }
                partial_sum=0;
                continue;
            }
        }
        if (partial_sum>prev_best){
            prev_best=partial_sum;
        }


    }
    return prev_best;
}//exist positive

int maxSubArray(vector<int>& nums) {
    int partial_sum=0;
    int prev_best=nums[0];
    if (nums.size()==1){return nums[0];}
    for (auto& item:nums){
        if (partial_sum>0){
            partial_sum+=item;
        }else{
            partial_sum=item;
        }
        prev_best=max(partial_sum,prev_best);
    }
    return prev_best;
}


}

int main() {

    std::vector<int> test2;
    test2.push_back(2);

    test2.push_back(3);

    //test2.push_back(-1);


   // test2.push_back(-5);

    cout<<maxSubArray(test2)<<endl;
    return 0;
}
