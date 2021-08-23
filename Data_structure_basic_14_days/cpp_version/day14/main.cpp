#include <iostream>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
//#98
class Solution {
public:
    TreeNode* pre_node= nullptr;
    bool isValidBST(TreeNode* root) {
        if (root== nullptr) {return true;}

        bool left=isValidBST(root->left);

        if (pre_node!= nullptr&&pre_node->val>=root->val){
            return false;
        }

        pre_node=root;
        bool right=isValidBST(root->right);

        return left&&right;

    }
};
//#653
bool find_helper(TreeNode* root, int k,unordered_set<int>& hash){
    if (root== nullptr){
        return false;
    }
    if (hash.count(k-root->val)==1){
        return true;
    } else{
        hash.insert(root->val);
        return find_helper(root->left,k,hash)||find_helper(root->right,k,hash);
    }



}
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> hash;
    return find_helper(root,k,hash);
}

//#235
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root== nullptr){
        return nullptr;
    }
    if (p==root||q==root){
        return root;
    }
    if ((p->val<root->val&&q->val>root->val)||(p->val>root->val&&q->val<root->val)){
        return root;
    }
    if (p->val<root->val&&q->val<root->val){
        return lowestCommonAncestor(root->left,p,q);
    }else{
        return lowestCommonAncestor(root->right,p,q);
    }

}

int main() {
    TreeNode* t1=new TreeNode(2);
    TreeNode* t2=new TreeNode(4);
    TreeNode* t3=new TreeNode(7);
    TreeNode* t4=new TreeNode(3,t1,t2);
    TreeNode* t5=new TreeNode(6, nullptr,t3);
    TreeNode* t6=new TreeNode(5,t4,t5);
    cout<<findTarget(t6,9)<<endl;
    return 0;
}
