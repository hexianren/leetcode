
class Solution {
    public int strStr(String haystack, String needle) {
        int temp = 0;
        int result = -1;
        if (haystack == null) {
            return -1;
        }

        if (needle == null) {
            return -1;
        }

        if ("".equals(haystack) && "".equals(needle)) {
            return 0;
        }

        if (!"".equals(haystack) && "".equals(needle)) {
            return 0;
        }

        if ("".equals(haystack) && !"".equals(needle)) {
            return -1;
        }

        if (haystack.length() < needle.length()) {
            return -1;
        }

        char hayChar, needleChar;
        for (int i = 0;i < haystack.length();i++) {
            hayChar = haystack.charAt(i);
            if (temp < needle.length()) {
                needleChar = needle.charAt(temp);
                if (needleChar == hayChar) {
                    if (result == -1) {
                        result = i;
                    }
                    temp++;
                } else {
                    if (result != -1) {
                        i = result;
                    }
                    temp = 0;
                    result = -1;
                }
            }
        }

        //"mississippi", "issipi" mississippi最后一个字母和issipi的第一个字母相等，需要判断长度最少是needle.length())
        if (haystack.length() - result >= needle.length()) {
            return result;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().strStr("mississippi", "issipi"));
    }
}