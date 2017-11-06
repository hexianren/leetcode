class Solution {
    public boolean isPalindrome(int x) {
	int digit = 0;
	int temp = x;
	while(true) {
		if (temp != 0) {
			digit++;
			temp = temp / 10;
		} else {
			break;
		}
	}

	if (digit == 0  ||digit == 1) {
		return true;
	}
	int length = (int)Math.pow(10, digit - 1);

	while(length > 0) {
		int right = x % 10;
		int left = x / length;
		if (right != left) {
			return false;
		}

		x = (x - left * length) / 10;
		length /= 100;
	}
	return true;
    }

    public static void main(String[] args) {
	    System.out.println(new Solution().isPalindrome(123221));
    }
}
