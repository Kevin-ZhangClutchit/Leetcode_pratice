#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

//#876
ListNode* middleNode(ListNode* head) {
    if (head== nullptr){return head;}
    else{
        ListNode* fast=head;
        ListNode* slow=head;
        while (fast!= nullptr&&fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
}

//#19
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head== nullptr){return head;}
    else if (head->next== nullptr){return nullptr;}
    else{
        ListNode* slow_pre= nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while (n){
            fast=fast->next;
            n--;
        }
        while (fast!= nullptr){
            slow_pre=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if (slow_pre!= nullptr){
            slow_pre->next=slow->next;
            delete slow;
        }else{
            head=head->next;
            delete slow;
        }
        return head;


    }
}
int main() {
    ListNode* l2=new ListNode(2, nullptr);
    ListNode* l1=new ListNode(1,l2);
    ListNode* answer=removeNthFromEnd(l1,2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
