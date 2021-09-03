#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//#3 Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
    if (s.empty()){
        return 0;
    }
    if (s.size()==1){
        return 1;
    }
    if (s.size()==2){
        return s[0]==s[1]?1:2;
    }
    size_t left=0;
    size_t right=0;
    int result=0;
    unordered_set<char> hash;
    while (right<s.size()){
        while (hash.count(s[right])==0&&right<s.size()){
            hash.insert(s[right]);
            right++;
        }
        result=max(result,(int)hash.size());
        hash.erase(s[left]);
        left++;
    }
    return result;
}
//#567 Permutation in String
bool checkInclusion(string s1, string s2) {
    unordered_map<char,int> hash;//<char,times>
    //store s1 information
    if (s1.empty()){
        return false;
    }else if (s1.size()==1){
        for (auto &item:s2) {
            if (s1[0]==item){
                return true;
            }
        }
        return false;
    }
    for (auto &item:s1) {
        if (hash.find(item)==hash.end()){
            hash.insert(make_pair(item,1));
        }else{
            hash[item]++;
        }
    }
    size_t left=0;
    size_t right=s1.size()-1;
    unordered_map<char,int> dynamic_hash=hash;
    while (right<s2.size()){
        size_t flag=0;
        for (size_t i = left; i <= right; ++i) {
            if (dynamic_hash.find(s2[i])==dynamic_hash.end()){
                break;
            }else{
                if (dynamic_hash[s2[i]]==0){
                    break;
                }else{
                    dynamic_hash[s2[i]]--;
                    flag++;
                }
            }
        }
        if (flag==s1.size()){
                return true;
        }else{
            dynamic_hash=hash;
            left++;
            right++;
        }

    }
    return false;

}
int main() {
    string s="aaa";
    cout<<lengthOfLongestSubstring(s)<<endl;

    string s1="abc";
    string s2="dcda";
    cout<<checkInclusion(s1,s2)<<endl;
    return 0;
}
