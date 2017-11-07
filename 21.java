class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode result = null;
        ListNode temp = null;
        if (l1 == null && l2 == null) {
            return null;
        }

        if (l1 == null) {
            return l2;
        }

        if (l2 == null) {
            return l1;
        }

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                if (result == null) {
                    result = l1;
                    temp = result;
                } else {
                    temp.next = l1;
                    temp = temp.next;
                }
                l1 = l1.next;
            } else if (l2.val < l1.val) {
                if (result == null) {
                    result = l2;
                    temp = result;
                } else {
                    temp.next = l2;
                    temp = temp.next;
                }
                l2 = l2.next;
            } else if (l1.val == l2.val) {
                if (result == null) {
                    result = new ListNode(l1.val);
                    temp = result;
                    temp.next = new ListNode(l2.val);
                    temp = temp.next;
                } else {
                    temp.next = new ListNode(l1.val);
                    temp = temp.next;
                    temp.next = new ListNode(l2.val);
                    temp = temp.next;
                }
                l1 = l1.next;
                l2 = l2.next;
            }
        }

        if (l1 == null && l2 != null) {
            temp.next = l2;
        }

        if (l2 == null && l1 != null) {
            temp.next = l1;
        }
        return result;
    }
}