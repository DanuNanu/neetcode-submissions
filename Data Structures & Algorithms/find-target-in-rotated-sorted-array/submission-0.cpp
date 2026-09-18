class Solution {
public:
    int search(vector<int>& nums, int target) {
        //main idea: if mid is less than right
        // that means that there is some transformation t <n
        //so then what u do, is that you check in that case,
        //if target is less than mid
        // if target is more than mid and say that midd is more than right
        // then you know that target is on the left
        // now if target is less than mid, and mid is more than right
        // that means you check if target is greater or less than left
        // cause we know that left is more than right
        // now if it is greater than left, then clearly
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[mid] > target) {
                //min must be on the right
                if (nums[mid] > nums[right]) {
                    if (target == nums[right]) {
                        return right;
                    } else if (target < nums[right]) {
                        //this means its between mid and right
                        left = mid+1;
                        continue;
                    } else {
                        //then target > nums[right]
                        //also nums[middle] > target
                        // then must be on the left
                        right = mid-1;
                        continue;
                    }
                } else {
                    //we know middle > target
                    // and also that middle < right
                    // so between left and middle
                    right = mid-1;
                    continue;
                }
            } else {
                //mid < target
                if (nums[mid] > nums[right]) {
                    //now middle > right, so right has min
                    // so it must be on the right
                    left = mid+1;
                    continue;
                } else {
                    // mid < right
                    // mid < target
                    //could be on left or right
                    if (target == nums[right]) {
                        return right;
                    } else if (target < nums[right]) {
                        //then must be on the right
                        left = mid+1;
                        continue;
                    } else {
                        // must be left
                        right = mid-1;
                        continue;
                    }
                }
            }
        }
        return -1;
    }
};
