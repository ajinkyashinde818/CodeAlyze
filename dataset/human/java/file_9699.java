import java.io.*;
import java.util.*;

public class Main {
    public static Node node[];
    public static String nodetype[];
 
    private static class Node{
        int id;
        int left;
        int right;
        int parent;
        int sibling;
        int degree;
        
        Node(int d, int le, int ri,int deg){
            this.id = d;
            this.left = le;
            this.right = ri;
            this.parent = -1;
            this.sibling = -1;
            this.degree = deg;
        }
    }
    
    
    public static int depth(Node child){
        int cnt = 0;
        
        if (child.parent == -1)return cnt;
        
        cnt = depth(node[child.parent]) + 1;
        
        return cnt;
    }
    
    public static int height(Node child){
        int cnt_left = 0;
        int cnt_right = 0;
        
        if (child.left == -1 && child.right != -1){
            cnt_right = height(node[child.right]) + 1;
        }else if (child.left != -1 && child.right == -1){
            cnt_left = height(node[child.left]) + 1;
        }else if  (child.left != -1 && child.right != -1){
            cnt_right = height(node[child.right]) + 1;
            cnt_left = height(node[child.left]) + 1;
        }
  
        if (cnt_left > cnt_right){
             return cnt_left;
        }else{
             return cnt_right;
        }
       
    }
    
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        node = new Node[n];
        nodetype = new String[n];
        
        for (int i = 0; i < n; i++){
            int id = in.nextInt();
            int left = in.nextInt();
            int right = in.nextInt();
            int degree = 2;
            if (left == -1 && right != -1){
                degree = 1;
            }else if (right == -1 && left !=-1){
                degree = 1;
            }else if (left == -1 && right == -1){
                degree = 0;
            }
            
            node[id] = new Node(id,left,right,degree);
            
        }
        
        for(int i = 0; i < n; i++){
            Node head = node[i];
            for(int j = 0; j < head.degree; j++){
                if(head.left != -1){
                    node[head.left].parent = head.id;
                    node[head.left].sibling = head.right;
                }
                if(head.right != -1){
                    node[head.right].parent = head.id;
                    node[head.right].sibling = head.left;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            Node head = node[i];
            if(node[head.id].parent == -1){
                nodetype[i] = "root";
            }else if(node[head.id].degree > 0){
                nodetype[i] = "internal node";
            }else if(node[head.id].degree == 0){
                nodetype[i] = "leaf";
            }
        }
        
          
        for(int i = 0; i < n; i++){
            Node head = node[i];
            if (nodetype[i] != "leaf"){
                System.out.println("node " + head.id + ": parent = " + head.parent + ", sibling = " + head.sibling + ", degree = " + head.degree + ", depth = " + depth(head) + ", height = " + height(head) + ", "+ nodetype[i]);
             
            }else if(nodetype[i] == "leaf"){
                System.out.println("node " + head.id + ": parent = " + head.parent + ", sibling = " + head.sibling + ", degree = " + head.degree + ", depth = " + depth(head)  + ", height = " + height(head) + ", " + nodetype[i]);
            }

        }
      
    }  
}
