package linkedlists;

public class RotateLinkedList {

      public class ListNode {
          int val;
          ListNode next;
          ListNode() {}
          ListNode(int val) { this.val = val; }
          ListNode(int val, ListNode next) { this.val = val; this.next = next; }
        }


    public static ListNode rotateRight(ListNode head, int k) {

            if(k ==0) return head;
            int size = 1;

            ListNode fast = head;
            ListNode slow = head;

            while(fast.next != null){
                size++;
                fast = fast.next;
            }
            //slow points to the item where the cycle starts
            // use to break cycle later on
            for(int cycle = size - k % size;  cycle > 1; cycle--){
                slow = slow.next;
            }

            fast.next = head;
            head = slow.next;
            slow.next = null;

            return head;

        }
    }

