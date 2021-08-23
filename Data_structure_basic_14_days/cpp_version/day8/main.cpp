#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

//#206
ListNode* reverse_helper(ListNode* head,ListNode* head_next){
    if (head_next== nullptr){
        return head;
    }else{
        ListNode* tmp=head_next->next;
        head_next->next=head;
        return reverse_helper(head_next,tmp);
    }
}
ListNode* reverseList(ListNode* head) {
    if (head== nullptr){
        return nullptr;
    }else if (head->next== nullptr){
        return head;
    }else{
        ListNode* tmp=head->next;
        head->next= nullptr;
        return reverse_helper(head,tmp);

    }

}

//#83
ListNode* deleteDuplicates(ListNode* head) {
    if (head== nullptr){
        return head;
    }
    if (head->next== nullptr){
        return head;
    }

    ListNode* result=head;
    while (head->next!= nullptr){
        if (head->val!=head->next->val){
            head=head->next;
        } else{
            ListNode* tmp=head->next;
            head->next=head->next->next;
            delete tmp;
        }
    }
    return result;
}
int main() {
    ListNode* l4=new ListNode(4, nullptr);
    ListNode* l3=new ListNode(3, l4);
    ListNode* l2=new ListNode(2, l3);
    ListNode* l1=new ListNode(1, l2);
    ListNode* result=reverseList(l1);

    ListNode* l8=new ListNode(2, nullptr);
    ListNode* l7=new ListNode(2, l8);
    ListNode* l6=new ListNode(1, l7);
    ListNode* l5=new ListNode(1, l6);
    ListNode* result2=deleteDuplicates(l5);
    return 0;
}
