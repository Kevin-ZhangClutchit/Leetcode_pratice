#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
//#102
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> answer;
    if (root== nullptr){return answer;}
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        vector<int> current_level;
        int size=q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* tmp=q.front();
            q.pop();
            current_level.emplace_back(tmp->val);
            if (tmp->left!= nullptr){
                q.push(tmp->left);
            }
            if (tmp->right!= nullptr){
                q.push(tmp->right);
            }
        }
        answer.emplace_back(current_level);
    }
    return answer;
}

//#104
int maxDepth_helper(TreeNode* root,int Depth){
    if (root==nullptr){return Depth;}
    else return max(maxDepth_helper(root->left,Depth+1),maxDepth_helper(root->right,Depth+1));
}
int maxDepth(TreeNode* root) {
    if (root== nullptr){return 0;}
    else return maxDepth_helper(root,0);
}

//#101
bool Symmetric_helper(TreeNode* l,TreeNode* r){
    if (l== nullptr&&r== nullptr){
        return true;
    }else if ((l== nullptr&&r != nullptr)||(l!= nullptr&&r == nullptr)){
        return false;
    }else{
        return (l->val==r->val)&&Symmetric_helper(l->left,r->right)&&Symmetric_helper(l->right,r->left);
    }
}
bool isSymmetric(TreeNode* root) {
    if (root== nullptr){return true;}
    else{
        return Symmetric_helper(root->left,root->right);
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
