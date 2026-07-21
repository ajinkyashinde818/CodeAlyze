import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.Point;
 
public class Main {
	//static final long MOD = 998244353L;
	//static final long INF = 1000000000000000007L;
	static String letters = "abcdefghijklmnopqrstuvwxyz";
	static final long MOD = 1000000007L;
	static final int INF = 1000000007;
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter pw = new PrintWriter(System.out);
		
		long N = sc.nl();
		ArrayList<Integer> pows = new ArrayList<Integer>();
		for (long i = 2; i*i <= N; i++) {
			if (N%i==0) {
				int pow = 0;
				while (N%i==0) {
					N /= i;
					pow++;
				}
				pows.add(pow);
			}
		}
		
		if (N>1)
			pows.add(1);
		
		int ans = 0;
		for (int p: pows) {
			if (p >= 36) {
				ans += 8;
			} else if (p >= 28) {
				ans += 7;
			} else if (p >= 21) {
				ans += 6;
			} else if (p >= 15) {
				ans += 5;
			} else if (p >= 10) {
				ans += 4;
			} else if (p >= 6) {
				ans += 3;
			} else if (p >= 3) {
				ans += 2;
			} else {
				ans += 1;
			}
		}
		
		pw.println(ans);
		
		pw.close();
	}
	
	static class SegmentTree {
		public int[] tree;
		public int N;
 
		//Zero initialization
		public SegmentTree(int n) {
			N = n;
			tree = new int[4*N+1];
		}
		
		public int query(int treeIndex, int lo, int hi, int i, int j) {
			// query for arr[i..j]
			if (lo > j || hi < i)
				return 0;
			if (i <= lo && j >= hi)
				return tree[treeIndex];
			int mid = lo + (hi - lo) / 2;
 
			if (i > mid)
				return query(2 * treeIndex + 2, mid + 1, hi, i, j);
			else if (j <= mid)
				return query(2 * treeIndex + 1, lo, mid, i, j);
 
			int leftQuery = query(2 * treeIndex + 1, lo, mid, i, mid);
			int rightQuery = query(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);
 
			// merge query results
			return merge(leftQuery, rightQuery);
		}
 
		public void update(int treeIndex, int lo, int hi, int arrIndex, int val) {
			if (lo == hi) {
				tree[treeIndex] = val;
				return;
			}
 
			int mid = lo + (hi - lo) / 2;
 
			if (arrIndex > mid)
				update(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
			else if (arrIndex <= mid)
				update(2 * treeIndex + 1, lo, mid, arrIndex, val);
 
			// merge updates
			tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
		}
 
		public int merge(int a, int b) {
			return Math.max(a,b);
		}
	}
	
 
	public static long dist(long[] p1, long[] p2) {
		return (Math.abs(p2[0]-p1[0])+Math.abs(p2[1]-p1[1]));
	}
	
	//Find the GCD of two numbers
	public static long gcd(long a, long b) {
		if (a < b) return gcd(b,a);
		if (b == 0)
			return a;
		else
			return gcd(b,a%b);
	}
	
	//Fast exponentiation (x^y mod m)
	public static long power(long x, long y, long m) { 
		if (y < 0) return 0L;
		long ans = 1;
		x %= m;
		while (y > 0) { 
			if(y % 2 == 1) 
				ans = (ans * x) % m; 
			y /= 2;  
			x = (x * x) % m;
		} 
		return ans; 
	}
	
	public static int[] shuffle(int[] array) {
		Random rgen = new Random();
		for (int i = 0; i < array.length; i++) {
		    int randomPosition = rgen.nextInt(array.length);
		    int temp = array[i];
		    array[i] = array[randomPosition];
		    array[randomPosition] = temp;
		}
		return array;
	}
	
	public static long[] shuffle(long[] array) {
		Random rgen = new Random();
		for (int i = 0; i < array.length; i++) {
		    int randomPosition = rgen.nextInt(array.length);
		    long temp = array[i];
		    array[i] = array[randomPosition];
		    array[randomPosition] = temp;
		}
		return array;
	}
	
	public static int[][] shuffle(int[][] array) {
		Random rgen = new Random();
		for (int i = 0; i < array.length; i++) {
		    int randomPosition = rgen.nextInt(array.length);
		    int[] temp = array[i];
		    array[i] = array[randomPosition];
		    array[randomPosition] = temp;
		}
		return array;
	}
	
    public static int[][] sort(int[][] array) {
    	//Sort an array (immune to quicksort TLE)
 
		Arrays.sort(array, new Comparator<int[]>() {
			  @Override
        	  public int compare(int[] a, int[] b) {
				  return a[0]-b[0]; //ascending order
	          }
		});
		return array;
	}
    
    public static long[][] sort(long[][] array) {
    	//Sort an array (immune to quicksort TLE)
		Random rgen = new Random();
		for (int i = 0; i < array.length; i++) {
		    int randomPosition = rgen.nextInt(array.length);
		    long[] temp = array[i];
		    array[i] = array[randomPosition];
		    array[randomPosition] = temp;
		}
		Arrays.sort(array, new Comparator<long[]>() {
			  @Override
        	  public int compare(long[] a, long[] b) {
				  if (a[0] < b[0])
					  return -1;
				  else
					  return 1;
	          }
		});
		return array;
	}
    
    static class FastScanner { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastScanner() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine());
                } catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        }
        
        int ni() { 
            return Integer.parseInt(next()); 
        }
  
        long nl() { 
            return Long.parseLong(next()); 
        } 
  
        double nd() { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() {
            String str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) {
                e.printStackTrace(); 
            } 
            return str;
        }
    }
}
