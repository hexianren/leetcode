
class Solution {
    public String countAndSay(int n) {
        String result = "1";
        for (int i = 1;i < n;i++) {
           result = countAndSay(result);
        }
        return result;
    }

    public String countAndSay(String str) {
        int count = 0;
        StringBuilder result = new StringBuilder();
        char lastChar = '\0';
        char currChar;
        for (int i = 0; i < str.length();i++) {
           currChar = str.charAt(i);
           if (lastChar == '\0') {
               lastChar = currChar;
               count++;
           } else if (currChar == lastChar) {
               count++;
           } else if (currChar != lastChar) {
               result.append(count).append(lastChar);
               lastChar = currChar;
               count = 1;
           }
        }
        result.append(count).append(lastChar);
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(new Solution().countAndSay(5));
    }
}