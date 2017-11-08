public class Solution {
    public int removeElement(int[] nums, int val) {
        int i;
        int count = 0;
        int cursor = 0;
        for (i = 0;i < nums.length;i++) {
            while(cursor < nums.length && nums[cursor] == val) {
                if (cursor == nums.length - 1) {
                    break;
                }
                cursor++;
            }

            if (cursor == nums.length - 1 && nums[cursor] == val) {
                break;
            }

            nums[i] = nums[cursor];
            count++;
            if (cursor == nums.length - 1) {
                break;
            }
            cursor++;
        }

        return count;
    }

    public static void main(String[] args){
        int[] array = new int[] {3};
        System.out.println(new Test().removeElement(array, 3));
    }
}