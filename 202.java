public class Solution {
    public boolean isHappy(int n) {
                int i = 0;
        int temp = 0;
        int di = 0;
        HashSet<Integer> set = new HashSet<>();
        int magic = 0;
        while(true) {
            temp = 0;
            set.add(n);
            while (true) {
                di = n % 10;
                temp += di * di;
                n /= 10;
                if (n == 0) {
                    n = temp;
                    if (temp == 1) {
                        return true;
                    }

                    if (set.contains(n)) {
                        return false;
                    }
                    break;
                }
            }
        }
    }
}