import java.math.*;
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		int t = 1;
		while (t-->0) {
		    int k = sc.nextInt(), n = sc.nextInt();
		    int[] a = new int[n];
		    for (int i=0;i<n ;i++ ) a[i] = sc.nextInt();
		    Arrays.sort(a);
		    int max = 0;
		    for(int i=0;i<n-1;i++){
		        max = Math.max(max,a[i+1]-a[i]);
		    }
		    max = Math.max(max,k-a[n-1]+a[0]);
		    System.out.println(k-max);
		}
	}
	static ArrayList<Integer> key;
	static int n1;
	static void insert(int key1){
		key.add(key1);
		n1++;
		swim(n1);
	}
	static void swim(int k){
		while (k>1 && less(k/2, k)) {
			swap(k/2, k);
			k/=2;
		}
	}
	static int deleteMax(){
		int max = key.get(1);
		key.set(1,key.get(n1--));
		sink(1);
		key.remove(n1+1);
		return max;
	}
	static void sink(int k){
		while (2*k<=n1) {
			int j = 2*k;
			if (j<n1 && less(j,j+1)) {
				j++;
			}
			if (!less(k, j)) {
				break;
			}
			swap(k,j);
			k=j;
		}
	}
	static boolean less(int a, int b){
		return key.get(a)<key.get(b);
	}
	static void swap(int a, int b){
		int c=key.get(a);
		key.set(a,key.get(b));
		key.set(b,c);
	}
	static String getit(String s, String b){
	    StringBuilder temp=new StringBuilder(" ");
        temp.append(s);
        temp.append("#");
        temp.append(b);
	    int n = temp.length()-1;
	    String p = temp.toString();
	    int[] pi = new int[n+1];
	    pi[0] = -1;
	    int k = -1;
	    for (int i=1;i<=n ;i++ ){
	        while(k>=0 && p.charAt(k+1)!=p.charAt(i)) k = pi[k];
	        pi[i] = ++k;
	    } 
	    return s.substring(1,pi[n]);
	}
	static class Query {
		int x1, x2, y, id;
		public Query(int c, int d, int e, int a){
			x1 = c;
			x2 = d;
			y = e;
			id = a;
		}
	}
	static class Compare1 implements Comparator<Query>{
		@Override
		public int compare(Query q1, Query q2){
			if(q1.x2==q2.x2) return q1.x1-q2.x1;
			return q1.x2-q2.x2;
		}
	}
	static class Pair implements Comparable<Pair>{
		int a, b;
		public Pair(int c, int d){
			a = c;
			b = d;
		}
		public int compareTo(Pair p){
		    return a-p.a;
		}
	}
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}
		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}
		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
