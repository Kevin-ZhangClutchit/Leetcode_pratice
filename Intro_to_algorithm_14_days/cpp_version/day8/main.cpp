#include <iostream>

using namespace std;

//#617 Merge Two Binary Trees
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1== nullptr){
        return root2;
    }else if(root2 == nullptr){
        return root1;
    }else{
        TreeNode* root=new TreeNode;
        root->val=root1->val+root2->val;
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);
        return root;
    }

}



//#116 Populating Next Right Pointers in Each Node
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
void connect_recur(Node* root){
    if (root== nullptr||root->left== nullptr){
        return;
    }else{
        root->left->next=root->right;
        if (root->next!= nullptr){
            root->right->next=root->next->left;
        }
        connect_recur(root->left);
        connect_recur(root->right);
    }
}

Node* connect(Node* root) {
    if (root== nullptr){
        return nullptr;
    }else{
        connect_recur(root);
        return root;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
