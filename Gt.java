import java.util.ArrayList;
import java.util.Stack;

public class Gt {
    public static class Node{
        int data;
        ArrayList<Node> children;

        public Node(int data){
            this.data=data;
            this.children=new ArrayList<>();
        }
        public String toString(Node node){
            return node.data+"";
        }
    }

    public static Node constructTree(int[] arr){
        Stack<Node> st=new Stack<>();
        for(int i=0; i<arr.length-1; i++){
            if(arr[i]!=-1){
                st.push(new Node(arr[i]));
            } else {
                Node node=st.pop();
                st.peek().children.add(node);
            }
        }
        return st.peek();
    }

    public static void display(Node root){
        StringBuilder sb=new StringBuilder();
        sb.append(root.data);
        sb.append("->");
        for(Node child:root.children) sb.append(child.data+" ");
        System.out.println(sb);

        for(Node child:root.children) display(child);
    }

    public static int height(Node root){ // in terms of edges
        int h=-1;

        for(Node child:root.children) h=Math.max(h, height(child)+1);

        return h;
    }

    public static int size(Node root){
        int s=0;

        for(Node child:root.children) 
            s+=size(child);

        return s+1;
    }

    public static ArrayList<Node> NodeToRoot(Node root, int a){
        if(root.data==a){
            ArrayList<Node> ba=new ArrayList<>();
            ba.add(root);
            return ba;
        }

        ArrayList<Node> ans=new ArrayList<>();
        for(Node child:root.children){
            ans=NodeToRoot(child, a);
            if(ans.size()>0){
                ans.add(child);
                return ans;
            }
        }
        return ans;
    }

    public static boolean NodeToRoot_bool(Node root, int a, ArrayList<Node> al){
        for(Node child:root.children){
            if(child.data==a){
                al.add(child);
                return true;
            } else {
                if(NodeToRoot_bool(child, a, al)){
                    al.add(child);
                    return true;
                }
            }
        }
        return false;
    }

    public static void lca(Node root, int a, int b){
        ArrayList<Node> ntra=NodeToRoot(root,a);
        ArrayList<Node> ntrb=new ArrayList<>();
        NodeToRoot_bool(root,b,ntrb);
        ntrb.add(root);
        int i=ntra.size()-1;
        int j=ntrb.size()-1;
        

        while(i>=0 && j>=0 && ntra.get(i)==ntrb.get(j)){
            i--;
            j--;
        }
        
        i++;
        System.out.println(ntra.get(i).data);
    }

    // if we can fold it form between
    public static boolean isFoldable(Node node1, Node node2){
        if(node1.children.size()!=node2.children.size()) return false;

        for(int i=0, j=node1.children.size()-1; i<=j; i++,j--){
            Node a=node1.children.get(i);
            Node b=node2.children.get(j);

            if(!isFoldable(a,b)) return false;
        }
        return true;
    }

    // mirror ================================================================
    public static boolean isMirror(Node node1, Node node2){
        if(node1.children.size()!=node2.children.size() || node1.data!=node2.data) return false;

        for(int i=0, j=node1.children.size()-1; i<=j; i++,j--){
            Node a=node1.children.get(i);
            Node b=node2.children.get(j);

            if(!isMirror(a,b)) return false;
        }
        return true;
    }

    // linearize Tree ========================================================================
    public static void linearize(Node root){
        for(Node child:root.children){
            linearize(child);
        }

        for(int i=root.children.size()-2; i>=0;i--){
            Node node=root.children.get(i);
            Node tail=node;

            while(tail.children.size()>0)
                tail=tail.children.get(0);
                                      
            tail.children.add(root.children.get(i+1));
            root.children.remove(i+1);
        }
    }

    // linearize TREE better ==============================================================
    public static Node linearize_better(Node root){
        if(root.children.size()==0){
            return root;
        }

        int n=root.children.size();
        Node gTail=linearize_better(root.children.get(n-1));

        for(int i=n-2; i>=0; i--){
            Node tail=linearize_better(root.children.get(i));

            tail.children.add(root.children.get(i+1));
            root.children.remove(i+1);
        }
        return gTail;
    }

    public static void solve(){
        int[] arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};                                                                   ;
        Node root=constructTree(arr);
        display(root);
        System.out.println(height(root));
        System.out.println(size(root));

        //lca(root,70,120);

        linearize_better(root);
        display(root);
    }
    public static void main(String[] args) {
        solve();
    }
}
