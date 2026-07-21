import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

 public class Main {
     static Node[] ls;

     static class Node {
         int id = 0;
         int parent = -1;
         int left = -1;
         int right = -1;
         int depth = 0;
         int height = 0;

         Node(int id, int left, int right, int depth) {
             this.id = id;
             this.left = left;
             this.right = right;

             this.depth = depth;
         }
     }

     public static int getSibling(Node[] n, int idParent, int currentId) {
         for (Node no : n) {
             if (no.id == idParent) {
                 if (no.left != currentId) {
                     return no.left;
                 } else {
                     return no.right;
                 }

             }
         }

         return -1;
     }

     public static int getDegree(Node node) {
         int counter = 0;

         if (node.left != -1) {
             counter++;
         }

         if (node.right != -1) {
             counter++;
         }

         return counter;
     }

     public static String getType(Node n) {
         if (n.parent == -1) {
             return "root";
         } else if (n.left == -1 && n.right == -1) {
             return "leaf";
         } else {
             return "internal node";
         }
     }

     public static void getHeight(int id, int d) {
         ls[id].height = 0;
         ls[id].depth = d;

         if (ls[id].left != -1) {
             int h = ls[id].left;
             getHeight(h, d+1);
             if ((ls[h].height+1) > ls[id].height) {
                 ls[id].height = ls[h].height+1;
             }
         }

         if (ls[id].right != -1) {
             int h = ls[id].right;
             getHeight(h, d+1);
             if ((ls[h].height+1) > ls[id].height) {
                 ls[id].height = ls[h].height+1;
             }
         }
     }

     public static void main(String[] args) {
         Scanner inp = new Scanner(System.in);
         int n = inp.nextInt();

         ls = new Node[n];
         for (int i = 0; i < n; i++) {
             ls[i] = ls[i] = (new Node(i, -1, 0, 0));
         }

         for (int i = 0; i < n; i++){
             int id = inp.nextInt();
             int left = inp.nextInt();
             int right = inp.nextInt();

             ls[id].left = left;
             ls[id].right = right;

             if (left != -1) {
                 ls[left].parent = id;
             }

             if (right != -1) {
                 ls[right].parent = id;
             }
         }

         int nodeCount = 0;

         for ( Node no : ls) {
             if (no.parent == -1) {
                 getHeight(no.id, 0);
             }
         }

         for ( Node no : ls) {
             int degree = getDegree(no);

            System.out.println("node " + no.id + ": parent = " + no.parent + ", sibling = " + getSibling(ls, no.parent, no.id) + ", degree = " + degree + ", depth = " + no.depth + ", height = " + no.height + ", " + getType(no));
         }
     }
 }
