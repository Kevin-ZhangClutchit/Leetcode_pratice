#include <iostream>
#include <string>
#include <stack>
using namespace std;
//#20
bool isValid(string s) {
    if (s.empty()){
        return true;
    }
    if (s.size()==1){
        return false;
    }
    stack<char> stack;
    for (auto &item:s) {
        if (item=='('||item=='{'||item=='['){
            stack.push(item);
        }else{
            if (stack.empty()){return false;}
            else{

                if (item==')'){
                    if (stack.top()!='('){
                        return false;
                    }
                }else if (item-stack.top()!=2){
                    return false;
                }
                stack.pop();
            }

        }
    }
    return stack.empty();

}

//#232
class MyQueue {
private:
    stack<int>  push_stack;
    stack<int>  pop_stack;
public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {

        this->push_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (pop_stack.empty()){
            while (!this->push_stack.empty()){
                this->pop_stack.push(this->push_stack.top());
                this->push_stack.pop();
            }
        }
        int answer=this->pop_stack.top();
        this->pop_stack.pop();
        return answer;
    }

    /** Get the front element. */
    int peek() {
        if (pop_stack.empty()){
            while (!this->push_stack.empty()){
                this->pop_stack.push(this->push_stack.top());
                this->push_stack.pop();
            }
        }
        int answer=this->pop_stack.top();
        return answer;

    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (this->push_stack.empty())&&(this->pop_stack.empty());
    }
};
int main() {
    string s;
    s="([)]";
    std::cout << isValid(s) << std::endl;
    char a='(',b=')';
    std::cout<<a-b<<endl;
    return 0;
}

