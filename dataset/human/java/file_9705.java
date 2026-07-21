import java.util.Scanner;


public class Main {

	static Scanner scanner=new Scanner(System.in);
	static int n=scanner.nextInt();
	static Node[] nodes=new Node[n];
	 static class Node{
		Node p;
		int left,right;
		int id;
		Node(int id){
			this.id=id;
		}
		void print(){
			System.out.print("node "+this.id+": ");
			System.out.print("parent = "+((this.p==null) ?"-1":p.id)+", ");
			System.out.print("sibling = "+(this.p==null?"-1":(this.p.right!=this.id)?this.p.right:this.p.left)+", ");
			
			int degree=0;
			if(this.left!=-1)
				degree++;
			if(this.right!=-1)
				degree++;
			System.out.print("degree = "+degree+", ");
			
			Node p=this.p;
			int d=0;
			while(p!=null){
				d++;
				p=p.p;
			}
			System.out.print("depth = "+d+", ");
			
			int h=height(this.id);
			System.out.print("height = "+h+", ");
			String string="";
			if(this.p==null)
				string="root";
			else if(degree==0)
				string="leaf";
			else if(degree>=1)
				string="internal node";
			System.out.println(string);
		}
		private  int height(int root) {
			int h1=0,h2=0;
			if(nodes[root].left!=-1)
				h1=height(nodes[root].left)+1;
			if(nodes[root].right!=-1)
				h2=height(nodes[root].right)+1;
			
			return Math.max(h1, h2);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		for(int i=0;i<n;i++){
			nodes[i]=new Node(i);
		}
		for(int i=0;i<n;i++){
			int id=scanner.nextInt();
			int left=scanner.nextInt();
			int right=scanner.nextInt();
			nodes[id].left=left;
			nodes[id].right=right;
			if(left!=-1){
				nodes[left].p=nodes[id];
			}	
			if(right!=-1){
				nodes[right].p=nodes[id];
			}
			
		}
		for(int i=0;i<n;i++){
			nodes[i].print();
		}
	}

}
