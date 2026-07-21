import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		bTree tree=new bTree(n);
		
		for(int i=0;i<n;i++) {
			int id=Integer.parseInt(in.next()), L=Integer.parseInt(in.next()), R=Integer.parseInt(in.next());
			if(L!=-1) {
				tree.T[id].l=L;
				tree.T[L].p=id;
			}
			if(R!=-1) {
				tree.T[id].r=R;
				tree.T[R].p=id;
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		for(int i=0;i<n;i++) {
			out.printf("node %d: parent = %d, ",i,tree.T[i].p);
			out.printf("sibling = %d, degree = %d, ", tree.getSibling(i), tree.getDegree(i));
			out.printf("depth = %d, height = %d, ", tree.getDepth(i, 0), tree.getHeight(i));
			out.println(tree.getCat(i));
		}
		out.flush();
	}

}

class bTreeNode{
	int p=-1,l=-1,r=-1;
}

class bTree{
	static bTreeNode T[];
	
	bTree(int n){
		T=new bTreeNode[n];
		for(int i=0;i<n;i++)T[i]=new bTreeNode();
	}
	
	static int getSibling(int u) {
		if(T[u].p==-1)return -1;
		
		if(T[T[u].p].l==u) return T[T[u].p].r;
		else return T[T[u].p].l;
	}
	
	static int getDegree(int u) {
		int d=0;
		if(T[u].l!=-1)d++;
		if(T[u].r!=-1)d++;
		return d;
	}
	
	static int getDepth(int p, int d) {
		if(T[p].p!=-1)d=getDepth(T[p].p,++d);
		return d;
	}
	
	static int getHeight(int p) {
		int L=0,R=0;
		if(T[p].l==-1 && T[p].r==-1)return 0;
		if(T[p].l!=-1)L=getHeight(T[p].l);
		if(T[p].r!=-1)R=getHeight(T[p].r);
		return Math.max(L, R)+1;
	}
	
	static String getCat(int u) {
		String str;
		if(T[u].p==-1)str="root";
		else if(T[u].l==-1 && T[u].r==-1)str="leaf";
		else str="internal node";
		return str;
	}
}
