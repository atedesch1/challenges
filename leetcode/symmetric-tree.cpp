#include <queue>

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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isSymmetricRecursive(root->left, root->right);
    }

    bool isSymmetricRecursive(TreeNode *leftNode, TreeNode *rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) return true;
        if (leftNode == nullptr || rightNode == nullptr ||
            leftNode->val != rightNode->val)
            return false;

        return isSymmetricRecursive(leftNode->left, rightNode->right) &&
               isSymmetricRecursive(leftNode->right, rightNode->left);
    }

    bool isSymmetricIteratively(TreeNode *root) {
        if (root == nullptr) return true;
        auto queue = std::queue<TreeNode *>();
        queue.push(root->left);
        queue.push(root->right);

        while (!queue.empty()) {
            auto n1 = queue.front();
            queue.pop();
            auto n2 = queue.front();
            queue.pop();

            if (n1 == nullptr && n2 == nullptr) continue;
            if (n1 == nullptr || n2 == nullptr || n1->val != n2->val)
                return false;

            queue.push(n1->left);
            queue.push(n2->right);

            queue.push(n1->right);
            queue.push(n2->left);
        }
        return true;
    }
};
