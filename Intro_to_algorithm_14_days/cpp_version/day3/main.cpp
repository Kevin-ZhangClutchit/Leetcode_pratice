#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//#283 Move Zeroes
static bool compare (const int &a, const int &b){
    if (b==0){return true;}
    else {return false;}
}

void moveZeroes(vector<int>& nums) {
    std::stable_sort(nums.begin(),nums.end(),compare);
}

//#167 Two Sum II - Input array is sorted
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> answer;
    if (numbers.size()==2){answer={1,2};}
    else{
        std::size_t pre=0,last=numbers.size()-1;
        while (pre<=last){
            if (numbers[pre]+numbers[last]==target){
                answer.emplace_back(pre+1);
                answer.emplace_back(last+1);
                return answer;
            }
            if (numbers[pre]+numbers[last]>target){
                last--;
            }else{
                pre++;
            }

        }
    }
    return answer;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
