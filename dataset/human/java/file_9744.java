import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int num;
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		TreeNode[] node = new TreeNode[num];
		for(int i=0;i<num;i++) {
			node[i] = new TreeNode();
		}
		for(int i=0;i<num;i++) {
			int parent =sc.nextInt();
			int left = sc.nextInt();
			int right = sc.nextInt();
			node[parent].left = left;
			node[parent].right = right;
			if(left!=-1) {
				node[left].parent = parent;
			}
			if(right!=-1) {
				node[right].parent = parent;
			}
			
		}
		for(int i=0;i<num;i++) {
			System.out.println("node "+i+": parent = "+node[i].parent+", sibling = "+getSibling(node, i)+", degree = "+getDegree(node[i])
			+", depth = "+getDepth(node,i)+", height = "+getHeight(node,i)+", "+getType(node, i));
		}
		
	}	
	
	public static int getSibling(TreeNode[] node,int i) {
		int parent = node[i].parent;
		if(parent==-1)
			return -1;
		if(node[parent].left==i) 
			return node[parent].right;
		else
			return node[parent].left;
		
	}
	
	public static int getDegree(TreeNode node) {
		if(node.left!=-1&&node.right!=-1) {
			return 2;
		}else if(node.left!=-1||node.right!=-1) {
			return 1;
		}else {
			return 0;
		}
	}
	
	public static int getDepth(TreeNode[] node,int i) {
		int parent = node[i].parent;
		if(parent==-1) {
			return 0;
		}
		return getDepth(node,parent)+1;
	}
	
	public static int getHeight(TreeNode[] node,int i) {
		int left = node[i].left;
		int right = node[i].right;
		int leftValue=0;
		int rightValue=0;
		if(left!=-1) {
			leftValue = getHeight(node,left)+1;
		}
		if(right!=-1) {
			rightValue = getHeight(node,right)+1;
		}
		return leftValue>rightValue?leftValue:rightValue;
	}
	
	public static String getType(TreeNode[] node,int i) {
		if(node[i].parent==-1) {
			return "root";
		}else if(node[i].left>-1||node[i].right>-1) {
			return "internal node";
		}else {
			return "leaf";
		}
	}
	
		
}

class TreeNode {
	public int parent;
	public int left;
	public int right;

public TreeNode() {
	parent = -1;
}
}
