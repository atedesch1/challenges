#include <vector>

class Solution {
   public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int insertionIndex = m + n - 1, p1 = m - 1, p2 = n - 1;
             insertionIndex >= 0; insertionIndex--) {
            if (p2 < 0 || (p1 >= 0 && nums1[p1] >= nums2[p2])) {
                nums1[insertionIndex] = nums1[p1--];
            } else {
                nums1[insertionIndex] = nums2[p2--];
            }
        }
    }
};
