#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     //first decide which vector is smaller, store it in the hashtable
     unordered_map<int,int> hash;//<number,frequency>
     vector<int> answer;
     if (nums1.size()<=nums2.size()){
         for (auto &item:nums1){
             if (hash.find(item)==hash.end()){
                 hash.insert(make_pair(item,1));
             }else{
                 hash[item]++;
             }
         }
         for (auto &item:nums2) {
             if (hash.find(item)!=hash.end()&&hash[item]>0){
                 hash[item]--;
                 answer.emplace_back(item);
             }
         }
     } else{
         for (auto &item:nums2){
             if (hash.find(item)==hash.end()){
                 hash.insert(make_pair(item,1));
             }else{
                 hash[item]++;
             }
         }
         for (auto &item:nums1) {
             if (hash.find(item)!=hash.end()&&hash[item]>0){
                 hash[item]--;
                 answer.emplace_back(item);
             }
         }
     }
     return answer;



    }

int maxProfit(vector<int>& prices) {
     int max_prev_profit=0;
     int min_prev_cost=prices[0];
     for (auto &item:prices){
         if (item<min_prev_cost){min_prev_cost=item;}
         if (item-min_prev_cost>max_prev_profit){max_prev_profit=item-min_prev_cost;}
     }
    return (max_prev_profit>0)?max_prev_profit:0;
}
int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.emplace_back(1);
    nums1.emplace_back(2);
    nums1.emplace_back(2);
    nums1.emplace_back(1);
    nums2.emplace_back(2);
    vector<int> answer;
    answer=intersect(nums1,nums2);
    for (auto& item:answer) {
        cout<<item<<" ";
    }
    cout<<endl;

    vector<int> prices;
    prices.emplace_back(1);
    prices.emplace_back(2);
    cout<<maxProfit(prices)<<endl;
    return 0;
}
