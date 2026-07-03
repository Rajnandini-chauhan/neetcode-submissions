class Solution {
public:
    int trap(vector<int>& height) {
        // best approach, using 2 pointers and keeping track of laftmax and right max wall

        int l = 0, r = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];

                l++;
            }
            else
            {
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];

                r--;
            }
        }

        return water;
    }
};