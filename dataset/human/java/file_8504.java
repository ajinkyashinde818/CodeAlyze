import java.util.Scanner;
import java.util.HashMap;
import java.awt.Point;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int l = sc.nextInt();
		Unionfind uf1 = new Unionfind(n);
		for(int i = 0; i<k; i++){
			int p = sc.nextInt()-1;
			int q = sc.nextInt()-1;
			uf1.unite(p,q);
		}
		Unionfind uf2 = new Unionfind(n);
		for(int i = 0; i<l; i++){
			int r = sc.nextInt()-1;
			int s = sc.nextInt()-1;
			uf2.unite(r,s);
		}
		HashMap<Point,Integer> map = new HashMap<>();
		for(int i = 0; i<n; i++){
			Point p = new Point(uf1.root(i),uf2.root(i));
			if(map.containsKey(p)){
				map.put(p,map.get(p)+1);
			}else{
				map.put(p,1);
			}
		}
		for(int i = 0; i<n; i++){
			System.out.println(map.get(new Point(uf1.root(i),uf2.root(i))));
		}
	}
	static class Unionfind{
		int[] parent;
		int[] size;
		public Unionfind(int n){
			this.parent=new int[n];
			this.size=new int[n];
			for(int i = 0; i<n; i++){
				parent[i]=i;
			}
		}
		public int root(int t){
			if(parent[t]==t){
				return t;
			}else{
				return parent[t]=root(parent[t]);
			}
		}
		public void unite(int x,int y){
			if(same(x,y)){
				return;
			}
			int xroot=root(x);
			int yroot=root(y);
			parent[yroot]=xroot;
		}
		public boolean same(int x,int y){
			return root(x)==root(y);
		}
	}
}
