#include <stack>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        auto traversal = std::vector<int>();
        traverseInorderRecursive(root, traversal);
        return traversal;
    }

    void traverseInorderRecursive(TreeNode *root, std::vector<int> &traversal) {
        if (root == nullptr) return;
        if (root->left != nullptr)
            traverseInorderRecursive(root->left, traversal);
        traversal.push_back(root->val);
        if (root->right != nullptr)
            traverseInorderRecursive(root->right, traversal);
    }

    std::vector<int> inorderTraversalIterative(TreeNode *root) {
        auto traversal = std::vector<int>();
        auto s = std::stack<TreeNode *>();
        auto currentNode = root;
        while (currentNode != nullptr || !s.empty()) {
            while (currentNode != nullptr) {
                s.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = s.top();
            s.pop();
            traversal.push_back(currentNode->val);

            currentNode = currentNode->right;
        }
        return traversal;
    }
};
