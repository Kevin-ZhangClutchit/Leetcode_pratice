#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#344
void reverseString(vector<char>& s) {
    std::size_t string_size=s.size();
    if(string_size==0||string_size==1){
        return;
    }
    if (string_size%2==0){
        for (int i = 0; i <string_size/2 ; ++i) {
            swap(s[i],s[string_size-1-i]);
        }
        return;
    }else{
        for (int i = 0; i <(string_size-1)/2 ; ++i) {
            swap(s[i],s[string_size-1-i]);
        }
        return;
    }

}


//#557

string reverseWords(string s) {
    if (s.empty()||s.size()==1){
        return s;
    }else{
        std::size_t string_size=s.size();
        std::size_t begin=0,end;
        for (size_t i = 0; i < string_size+1; ++i) {
            if (s[i]==' '||s[i]=='\0'){
                end=i-1;
                while (begin<end){
                    swap(s[begin],s[end]);
                    begin++;
                    end--;
                }
                begin=i+1;
            }
        }
        return s;
    }
}
int main() {
    for (int i = 0; i < 3; ++i) {
        cout<<i<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
