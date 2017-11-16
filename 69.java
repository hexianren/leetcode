/**
 * 参考网上的例子
 */
class Solution {
    public int mySqrt(int x) {
        double begin = 0;
        double end = x;
        double result = 1;
        double mid = 1;
        while (Math.abs(result - x) > 0.000001) {
            mid = (begin + end) / 2;
            result = mid * mid;
            if (result > x) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        return (int) mid;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().mySqrt(101));
    }
}