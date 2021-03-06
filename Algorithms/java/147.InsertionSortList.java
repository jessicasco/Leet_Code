public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null) 
            return head;
        ListNode p = head.next;
        ListNode previous = head;
        while (p != null) {
            if (p.val >= previous.val) {
                previous = previous.next;
                p = p.next;
                continue;
            }
            previous.next = p.next;
            if (head.val >= p.val) {
                p.next = head;
                head = p;
            } else {
                ListNode q = head;
                ListNode q_previous = null;
                while (q.val <= p.val) {
                    q_previous = q;
                    q = q.next;
                }
                p.next = q;
                q_previous.next = p;
            }
            p = previous.next;
        }
        return head;
    }
}
