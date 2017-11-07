
/**
 * Created by peter on 2017/1/22.
 */
public class Solution {
    public String longestCommonPrefix(String[] strs) {
        String result = "";
        if (strs == null || strs.length == 0) {
            return "";
        }

        String first = strs[0];
        if (first == null || "".equals(first)) {
            return "";
        }

        for (int i = 1;i <= first.length();i++) {
            String temp = first.substring(0, i);
            for (int j = 0;j < strs.length;j++) {
                if (strs[j] != null && strs[j].startsWith(temp)) {
                    continue;
                } else {
                    temp = null;
                    break;
                }
            }
            if (temp != null) {
                result = temp;
            }
        }
        return result;
    }
}