import java.io.PrintWriter;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		
		int n=in.nextInt();
		BTNode[] tree=new BTNode[n];
		for(int i=0;i<n;i++)tree[i]=new BTNode();
		
		for(int i=0;i<n;i++) {
			int id=Integer.parseInt(in.next()),
					l=Integer.parseInt(in.next()),
					r=Integer.parseInt(in.next());
			
			if(l!=-1) {
				tree[id].lc=l;
				tree[l].p=id;
			}
			if(r!=-1) {
				tree[id].rc=r;
				tree[r].p=id;
			}
		}
		in.close();
		
		//print
		PrintWriter out=new PrintWriter(System.out);
		for(int i=0;i<n;i++) {
			out.print("node "+i+": ");
			out.print("parent = "+tree[i].p+", ");
			out.print("sibling = "+sibling(tree,i)+", ");
			out.print("degree = "+degree(tree,i)+", ");
			out.print("depth = "+depth(tree,i)+", ");
			out.print("height = "+height(tree,i,0)+", ");
			out.println(nodeType(tree,i));
			out.flush();
		}
		
	}
	
	static int sibling(BTNode[] tree,int p) {
		if(tree[p].p==-1)return -1;
		
		if(tree[tree[p].p].lc==p)return tree[tree[p].p].rc;
		else return tree[tree[p].p].lc;
	}
	
	static int degree(BTNode[] tree,int pos) {
		int cnt=0;
		
		if(tree[pos].lc!=-1)cnt++;
		if(tree[pos].rc!=-1)cnt++;
		
		return cnt;
	}
	
	static int depth(BTNode[] tree,int p) {
		int cnt=0,pos=p;

		while(tree[pos].p!=-1) {
			pos=tree[pos].p;
			cnt++;
		}

		return cnt;
	}
	
	static int height(BTNode[] tree,int pos,int h) {
		if(tree[pos].lc==-1 && tree[pos].rc==-1)return h;
		
		int l=0,r=0;
		if(tree[pos].lc!=-1)l=height(tree,tree[pos].lc,h+1);
		if(tree[pos].rc!=-1)r=height(tree,tree[pos].rc,h+1);
		
		if(l>r)return l;
		else return r;
	}
	
	static String nodeType(BTNode[] tree,int p) {
		if(tree[p].p==-1)return "root";
		else if(tree[p].lc==-1 && tree[p].rc==-1)return "leaf";
		else return "internal node";
	}

}

class BTNode{
	int p=-1,lc=-1,rc=-1;
}
