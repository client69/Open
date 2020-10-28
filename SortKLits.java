public class SortList {

//      Definition for singly-linked list.
     public static class ListNode {
         int val;
         ListNode next;
         ListNode() {}
         ListNode(int val) { this.val = val; }
         ListNode(int val, ListNode next) { this.val = val; this.next = next; }
      }


    public static ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode middle = getMiddleNode(head);
        ListNode left = sortList(head);
        ListNode right = sortList(middle);
        return mergeTwoSortedLists(left, right);

    }

    public static ListNode mergeTwoSortedLists(ListNode p1, ListNode p2){
         ListNode dummyHead = new ListNode();
         ListNode result = dummyHead;
         while (p1 != null && p2 != null){
             if (p1.val < p2.val){
                 result.next = p1;
                 p1 = p1.next;
             }else {
                 result.next = p2;
                 p2 = p2.next;
             }
             result = result.next;

         }
         result.next = (p1 == null)? p2 : p1;

         return dummyHead.next;
    }
    public static ListNode getMiddleNode(ListNode head){
         ListNode slow = null;
         ListNode fast = head;
         while(fast != null && fast.next != null){
             slow = slow == null? head : slow.next;
             fast= fast.next.next;
         }
         ListNode mid = slow.next;
         slow.next = null;
         return mid;


    }


    public static void main(String[] args) {
        ListNode head = new ListNode(4);
        head.next = new ListNode(2);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(3);
        ListNode dummy = head;
        ListNode result = sortList(dummy);
        while (result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }
}
