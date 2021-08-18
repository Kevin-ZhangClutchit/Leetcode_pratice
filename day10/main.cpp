#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

void preorder_helper(TreeNode* root,vector<int>& result){
    if (root== nullptr){return;}
    else{
        result.emplace_back(root->val);
        preorder_helper(root->left,result);
        preorder_helper(root->right,result);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root!= nullptr){
        preorder_helper(root,result);
    }
    return result;

}
void inorder_helper(TreeNode* root,vector<int>& result){
    if (root== nullptr){return;}
    else{
        inorder_helper(root->left,result);
        result.emplace_back(root->val);
        inorder_helper(root->right,result);
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root!= nullptr){
        inorder_helper(root,result);
    }
    return result;
}

void postorder_helper(TreeNode* root,vector<int>& result){
    if (root== nullptr){return;}
    else{
        postorder_helper(root->left,result);
        postorder_helper(root->right,result);
        result.emplace_back(root->val);

    }
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root!= nullptr){
        postorder_helper(root,result);
    }
    return result;
}
int main() {
    vector<int> test;
    TreeNode* a=new TreeNode(1, nullptr, nullptr);
    test=preorderTraversal(a);
    return 0;
}
