import java.util.Arrays;

class Solution {
    public int[] plusOne(int[] digits) {
        boolean carry = true;
        int[] result;
        for (int i = digits.length - 1;i >= 0;i--) {
            if (carry) {
                digits[i]++;
            }

            carry = ((digits[i] / 10) == 1 ? true : false);
            digits[i] %= 10;
        }
        if (carry) {
           result = new int[digits.length + 1];
           result[0] = 1;
           System.arraycopy(digits, 0, result, 1, digits.length);

        } else {
            result = digits;
        }
        return result;
    }

    public static void main(String[] args) {
        new Solution().plusOne(new int[]{9 , 9 ,9});
    }
}