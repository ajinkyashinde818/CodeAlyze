import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node nodes[] = new Node[n];
        for(int i = 0 ; i < n ; i++)
            nodes[i] = new Node(i);
        for(int i = 0 ; i < n ; i++){
            int index = sc.nextInt();
            int l = sc.nextInt();
            int r = sc.nextInt();
            if(l != -1)
                nodes[index].left = nodes[l];
            if(r != -1)
                nodes[index].right = nodes[r];
        }
	for(int i = 0 ; i < n ; i++){
		if(nodes[i].right != null)
		    nodes[i].right.parent = nodes[i];
		if(nodes[i].left != null)
		    nodes[i].left.parent = nodes[i];
	}
        for(int i = 0 ; i < n ; i++)
            System.out.println("node " + nodes[i].index + ": parent = " + nodes[i].get_parent() + ", sibling = " + nodes[i].sibling() + ", degree = " + nodes[i].degree() + ", depth = " + nodes[i].depth() + ", height = " + nodes[i].height() + ", " + nodes[i].type());
    }
}
class Node{
    int index;
    Node parent = null;
    Node left = null;
    Node right = null;
    int get_parent(){
        if(parent == null)
            return -1;
        else
            return parent.index;
    }
    int depth(){
        if(parent == null)
            return 0;
        else
            return parent.depth() + 1;
    }
    int degree(){
        int count = 0;
        if(left != null)
            count++;
        if(right != null)
            count++;
        return count;
    }
    int sibling(){
        if(parent == null)
            return -1;
        else{
            if(parent.right == null || parent.left == null)
                return -1;
            else{
                if(parent.right.index == this.index)
                    return parent.left.index;
                else
                    return parent.right.index;
            }
        }
    }
    int height(){
        if(right == null && left == null)
            return 0;
        else if(left == null)
            return right.height()+1;
        else if(right == null)
            return left.height()+1;
        else
            return Math.max(right.height(),left.height())+1;
    }
    String type(){
        if(parent == null)
            return "root";
        else if(left == null && right == null)
            return "leaf";
        else
            return "internal node";
    }
    Node(int index){
        this.index = index;
    }
}
