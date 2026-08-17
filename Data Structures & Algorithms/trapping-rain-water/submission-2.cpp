class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        int lmax = height[0];
        int rmax = height[n - 1];

        for (int i = 1; i < n; i++) {
            lmax = max(lmax, height[i - 1]);
            left_max[i] = lmax;
        }

        for (int i = n - 2; i >= 0; i--) {
            rmax = max(rmax, height[i + 1]);
            right_max[i] = rmax;
        }

        int total_area = 0;
        for (int i = 1; i < n - 1; i++) {
            int temp_area = min(left_max[i], right_max[i]);
            if (height[i] < temp_area)
                total_area += temp_area - height[i];
        }

        return total_area;
    }
};