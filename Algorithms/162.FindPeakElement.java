public class Solution {
    public int findPeakElement(int[] nums) {
        return findPeakElement(nums, 0, nums.length-1);
    }

    private int findPeakElement(int[] nums, int start, int end) {
        if (start == end)
            return start;
        int mid = start + (end - start)/2;
        if ((mid == 0 || nums[mid] > nums[mid-1]) && (mid+1 > end || nums[mid] > nums[mid+1]))
            return mid;
        else if ((mid == 0 || nums[mid] > nums[mid-1]) && (mid+1 > end || nums[mid] < nums[mid+1]))
            return findPeakElement(nums, mid+1, end);
        else
            return findPeakElement(nums, start, end-1);
    }
}
