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
    bool isValidBST(TreeNode *root) {
        return validateBST(root, nullptr, nullptr);
    }

    bool validateBST(TreeNode *node, TreeNode *biggest, TreeNode *smallest) {
        if (node == nullptr) return true;
        if ((smallest != nullptr && node->val <= smallest->val) ||
            (biggest != nullptr && node->val >= biggest->val)) {
            return false;
        }
        return validateBST(node->left, node, smallest) &&
               validateBST(node->right, biggest, node);
    }
};
