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
//#226
void invert_helper(TreeNode* root){
    if (root== nullptr){return;}
    TreeNode* tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    invert_helper(root->left);
    invert_helper(root->right);
}
TreeNode* invertTree(TreeNode* root) {
    if (root== nullptr){return root;}
    invert_helper(root);
    return root;
}

//#112
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root== nullptr){return false;}
    else if (root->left== nullptr&&root->right== nullptr){return root->val==targetSum;}
    else return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
