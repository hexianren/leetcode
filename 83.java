/**
 * Created by QDHL on 2017/11/7.
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode result, fast, slow;
        if (head == null) {
            return null;
        }
        result = head;
        slow = head;
        fast = slow.next;
        while (fast != null) {
            if (slow.val == fast.val) {
                fast = fast.next;
                if (fast == null) { //最后两个重复，删除最后一个
                    slow.next = null;
                }
            } else {
                if (fast == slow.next) {
                    slow = fast;
                } else {
                    slow.next = fast;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(1);
        ListNode l3 = new ListNode(2);
        ListNode l4 = new ListNode(2);
        ListNode l5 = new ListNode(3);
        ListNode l6 = new ListNode(4);
        ListNode l7 = new ListNode(5);
        ListNode l8 = new ListNode(5);

        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;

        l5.next = l6;
        l6.next = l7;
        l7.next = l8;
        l8.next = null;

        ListNode h = new Solution().deleteDuplicates(l1);
        while (h != null) {
            System.out.println(h.val);
            h = h.next;
        }
    }
}
