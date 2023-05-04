#include <algorithm>
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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return maxDepthRecursive(root, 1);
    }

    int maxDepthRecursive(TreeNode *node, int depth) {
        if (node == nullptr) return depth - 1;
        return std::max(maxDepthRecursive(node->left, depth + 1),
                        maxDepthRecursive(node->right, depth + 1));
    }
};
