/**
 * Created by QDHL on 2017/11/7.
 */
public class Solution {
    /**
     * I 1
     * V 5
     * X 10
     * L 50
     * C 100
     * D 500
     * M 1000
     * 1.相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
     * 2.小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
     * 3.小的数字（限于 I、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
     * 4.正常使用时、连写的数字重复不得超过三次；
     * 5.在一个数的上面画一条横线、表示这个数扩大 1000 倍。
     * MDCCCLXXXVIII
     */
    public int romanToInt(String s) {
        int result = 0;
        int count = 0;
        int current = 0;
        int temp;
        for (int i = 0;i < s.length();i++) {
            switch (s.charAt(i)) {
                case 'I':
                    temp  = 1;
                    break;
                case 'V':
                    temp  = 5;
                    break;
                case 'X':
                    temp  = 10;
                    break;
                case 'L':
                    temp  = 50;
                    break;
                case 'C':
                    temp  = 100;
                    break;
                case 'D':
                    temp  = 500;
                    break;
                case 'M':
                    temp  = 1000;
                    break;
                default:
                    temp = 0;
                    break;
            }
            if (current == temp) {
                count++;
            } else {
                if ((current == 1 && temp > 1) || (current == 10 && temp > 10) || (current == 100 && temp > 100)) {
                    result -= current * count;
                } else {
                    result += current * count;
                }
                current = temp;
                count = 1;
            }
        }
        result += current * count;
        return result;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().romanToInt("MDCCCLXXXVIII"));
        System.out.println(new Solution().romanToInt("XCIX"));
        System.out.println(new Solution().romanToInt("CCC"));
    }
}
