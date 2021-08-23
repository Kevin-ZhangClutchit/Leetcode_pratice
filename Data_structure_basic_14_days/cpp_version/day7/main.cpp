#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//#141
bool hasCycle(ListNode *head) {
    if (!head){
        return false;
    }
    unordered_set<ListNode*> hash;
    while (head->next!= nullptr){
        if (hash.count(head)==1){
            return true;
        }else{
            hash.insert(head);
        }
        head=head->next;
    }
    return false;
}
//#21
void merge_helper(ListNode* l1, ListNode* l2,ListNode* merge_res){
    if (l1==nullptr){
        merge_res->next=l2;
        return;
    } else if (l2==nullptr){
        merge_res->next=l1;
        return;
    }
    if (l1->val<l2->val){
        merge_res->next=new ListNode(l1->val, nullptr);
        l1=l1->next;
        merge_res=merge_res->next;
    }else{
        merge_res->next=new ListNode(l2->val, nullptr);
        l2=l2->next;
        merge_res=merge_res->next;
    }
    merge_helper(l1,l2,merge_res);
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1==nullptr){
        return l2;
    }
    if (l2== nullptr){
        return l1;
    }
    ListNode* merge_res=new ListNode(-101);
    ListNode* copy=merge_res;
    if (merge_res->val==-101){
        if (l1->val<l2->val){
            merge_res->val=l1->val;
            l1=l1->next;
        }else{
            merge_res->val=l2->val;
            l2=l2->next;
        }
    }
    merge_helper(l1,l2,merge_res);
    return copy;

}
//A more precise recursion provided by comments
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2){
    if (l1==nullptr){
        return l2;
    }
    if (l2==nullptr){
        return l1;
    }
    if (l1->val<l2->val){
        l1->next=mergeTwoLists2(l1->next,l2);
        return l1;
    }else{
        l2->next=mergeTwoLists2(l1,l2->next);
        return l2;
    }
}

//#203
ListNode* removeElements(ListNode* head, int val) {
    if (head==nullptr){
        return nullptr;
    }
    if (head->val==val){
        ListNode* tmp=head;
        head=head->next;
        head=removeElements(head,val);
        delete tmp;
        return head;
    }else{
        head->next=removeElements(head->next,val);
        return head;
    }
}

int main() {
    ListNode* l1_3=new ListNode(4,nullptr);
    ListNode* l1_2=new ListNode(2,l1_3);
    ListNode* l1=new ListNode(1,l1_2);
    ListNode* l2_3=new ListNode(4,nullptr);
    ListNode* l2_2=new ListNode(3,l2_3);
    ListNode* l2=new ListNode(1,l2_2);
    ListNode* merge_res=mergeTwoLists(l1,l2);
    while (merge_res){
        cout<<merge_res->val<<" ";
        merge_res=merge_res->next;
    }
    cout<<endl;

    ListNode* delete_test3=new ListNode(3, nullptr);
    ListNode* delete_test2=new ListNode(3,delete_test3);
    ListNode* delete_test=new ListNode(1,delete_test2);
    ListNode* delete_res=removeElements(delete_test,3);
    return 0;
}