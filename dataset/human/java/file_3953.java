import java.util.*;
import java.io.*;
import java.math.*;
class Main{
	static int mod = (int)1e9+7;
	public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
	public static void main(String sp[])throws IOException{
		FastReader sc = new FastReader();
		
		int n = sc.nextInt();
		int arr[] = new int[n+1];
		int bi[] = new int[n+1];
		int sat[] = new int[n];
		
		for(int i=1;i<=n;i++)
			arr[i]=sc.nextInt();
		for(int i=1;i<=n;i++)
			bi[i]=sc.nextInt();
		for(int i=1;i<n;i++)
			sat[i]=sc.nextInt();
		
		long total=0;
		int prev=0;
		for(int i=1;i<=n;i++){
			int val = arr[i];
			if(prev+1==val){
				total+=bi[i];
				total+=sat[prev];
			
			}else{
				total+=bi[i];
			}
			prev=arr[i];	
		}
		
		System.out.println(total);
		
		
		
		
		
		
		out.close();
	}
	
	
	
	
	
	//static HashMap<Integer,Integer> visited = new HashMap<>();
		
	
	/*public static int compute(int root, int n, int m, Tree[] edge, int values[]){
			
			LinkedList<Integer> ll = 	new LinkedList<>();
			ll.add(root);
				
			while(ll.size()>0){
				int val = ll.removeFirst();
				visited.put(val,0);
				ArrayList<Integer> al = edge[val].al;
				int length = al.size();
				for(int i=0;i<length;i++){
					ll.addLast(al.get(i));
					int hold = edge[val].weight+values[root];
					values[al.get(i)] = Math.min(hold,values[al.get(i)]);
				}
			}
			return values[n];
			
	}*/
	
	
	public static class Tree{
		int weight;
		int destination;
	}
	
	
	
	public static int partition(int [] arr, int s, int e){
		
		int index=s;
		int pivot = arr[e];
		for(int i=s;i<=e-1;i++){
			if(arr[i]<=pivot){
				arr = swap(arr, index, i);
				index++;
			}
		}
		swap(arr,index,e);
		print(arr);
		return index;
	}
	
	public static int[] swap(int[] arr, int low, int high){
		int temp = arr[low];
		arr[low]=arr[high];
		arr[high]=temp;
		return arr;
	}
	
	
	public static long gcd(long a, long b){
		if(a==0)
			return b;
		
		return gcd(b%a,a);
	}
	
	public static void print(int[] arr){
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	
	public static class pair{
		int ai;
		int bi;
	}
	
	public static class comp implements Comparator<pair>{
		public int compare(pair o1, pair o2){
			return o1.bi-o2.bi;
		}
	}
	public static class FastReader {
		BufferedReader br;
		StringTokenizer st;
	
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception r) {
					r.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());//converts string to integer
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (Exception r) {
				r.printStackTrace();
			}
			return str;
		}
	}
	
}
