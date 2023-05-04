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
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        return attachChildren(nums, 0, nums.size() - 1);
    }

    TreeNode *attachChildren(std::vector<int> &nums, int l, int r) {
        if (l == r) return new TreeNode(nums[l]);
        if (l > r) return nullptr;

        int mid = (l + r) / 2;
        auto root = new TreeNode(nums[mid]);

        root->left = attachChildren(nums, l, mid - 1);
        root->right = attachChildren(nums, mid + 1, r);
        return root;
    }
};
