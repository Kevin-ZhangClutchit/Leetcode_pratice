#include <iostream>

using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//#700
TreeNode* searchBST(TreeNode* root, int val) {
    if (root== nullptr){
        return nullptr;
    }
    if (val==root->val){
        return root;
    }else{
        return val>root->val?searchBST(root->right,val):searchBST(root->left,val);
    }
}
//#701

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root== nullptr){
        root=new TreeNode(val);
        return root;
    }
    if (val>root->val){
        root->right=insertIntoBST(root->right,val);
    }else{
        root->left=insertIntoBST(root->left,val);
    }
    return root;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
