#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m=mat.size();
    int n=mat[0].size();
    if (m*n!=r*c){
        return mat;
    }
    vector<vector<int>> answer(r, vector<int>(c));
    for (int i = 0; i < r*c; ++i) {
        answer[i/c][i%c]=mat[i/n][i%n];
    }
    return answer;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(1, vector<int>(1, 1));
    if(numRows==1){
        return result;
    }

    for (int i=1; i<numRows;i++){
        vector <int> curr_row;
        for (int j=0;j<=i;j++){
            int left_index=j-1;
            int right_index=j;
            int tmp=0;
            if (left_index>=0){
                tmp+=result[i-1][left_index];
            }
            if (right_index<result[i-1].size()){
                tmp+=result[i-1][right_index];
            }

            curr_row.emplace_back(tmp);
        }
        result.emplace_back(curr_row);
    }
    return result;

}

//#1170
int frequency_cal(string& s){
    sort(s.begin(),s.end());
    int answer=1;
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i]==s[i+1]){
            answer++;
        } else{
            break;
        }
    }
    return answer;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int>answer;
    vector<int>words_frequency(12,0);
    for (auto &item:words){
        words_frequency[frequency_cal(item)]++;
    }
    for (int i = 1; i < 12; ++i) {
        words_frequency[i]+=words_frequency[i-1];
    }
    for (auto &item:queries) {
        answer.emplace_back(words.size()-words_frequency[frequency_cal(item)]);
    }
    return answer;
}

int main() {
    vector<vector<int>> mat(2,vector<int>(2));
    vector<vector<int>> test(2,vector<int>(2));
    int val=0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mat[i][j]=val;
            val++;
        }
    }
    int r=2,c=2;
    test=matrixReshape(mat,r,c);
    cout<<"Matrix Reshape"<<endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"Pascal Triangle"<<endl;
    vector<vector<int>> test2;
    test2=generate(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < i+1; ++j) {
            cout<<test2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    cout<<"String"<<endl;
    vector<string> queries;
    vector<string> words;
    vector<int> test3;
    queries.emplace_back("bbb");
    queries.emplace_back("cc");
    words.emplace_back("a");
    words.emplace_back("aa");
    words.emplace_back("aaa");
    words.emplace_back("aaaa");
    test3=numSmallerByFrequency(queries,words);
    for (auto &item: test3){
        cout<<item<<" ";
    }
    cout<<endl;



    return 0;
}
