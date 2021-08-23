#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

//#387 TODO: poor performance need improvement
int firstUniqChar(string s) {
    map<char,int>map;//<char,location>
    int cand=0;
    if (s.size()==1){return 0;}
    for (int i = 0; i < s.size(); ++i) {
        if (map.find(s[i])==map.end()){
            map.insert(make_pair(s[i],i));
            cand=i;
        } else{
            map[s[i]]=-1;
        }
    }
    for (auto &item: map) {
        if (item.second>=0&&item.second<cand){
            cand=item.second;
        }
    }
    if (map[s[cand]]==-1){return -1;}
    else{return cand;}
}

//#383
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int>hash;//<char,times>
    if (ransomNote.size()==1&&magazine.size()==1){
        return ransomNote==magazine;
    }
    for (auto &item:magazine){
        if (hash.find(item)==hash.end()){
            hash.insert(make_pair(item,1));
        }else{
            hash[item]++;
        }
    }
    for (auto &item:ransomNote) {
        if (hash.find(item)==hash.end()||hash[item]==0){
            return false;
        }else {
            hash[item]--;
        }
    }
    return true;
}

//#242
bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}
int main() {
    string s="leetcode";
    cout<<firstUniqChar(s)<<endl;
    return 0;
}
