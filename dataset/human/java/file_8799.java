import java.io.*;
import java.util.*;
//import java.math.*;
//import java.awt.Point;
 
public class Main {
	//static final long MOD = 998244353L;
	//static final long INF = -1000000000000000007L;
	static final long MOD = 1000000007L;
	//static final int INF = 1000000007;
	
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter pw = new PrintWriter(System.out);
		long A = sc.nl();
		long B = sc.nl();
		int K = sc.ni();
		long G = gcd(A,B);
		ArrayList<Long> nums = new ArrayList<Long>();
		for (int i = 1; i*i <= G; i++) {
			if (G % i == 0) {
				nums.add((long)i);
				if ((long)i != (G/i))
						nums.add(G/i);
			}
		}
		Collections.sort(nums);
		pw.println(nums.get(nums.size()-K));
		pw.close();
	}
	
	static class SegmentTree {

		public long[][] ranges;

		public SegmentTree(long[] array) {
			ranges = new long[4*array.length+1][4];
			for (int i = 0; i < array.length; i++) {
				add(1,1,array.length,i+1,i+1,array[i]);
			}
		}

		//range update nums[updateL..updateR] += val;
		public void add(int n, int L, int R, int updateL, int updateR, long val) {
			push(n,L,R);
			if (updateL <= L && R <= updateR) {
				//fully contained
				ranges[n][3] += val;
				push(n,L,R);
				return;
			} else if (L>updateR || R<updateL || L==R) {
				//not contained at all or leaf
				return;
			}
			add(2*n,L,(L+R)/2,updateL,updateR,val); 
			add(2*n+1,(L+R)/2+1,R,updateL,updateR,val);
			ranges[n][1] = Math.min(ranges[2*n][1],ranges[2*n+1][1]);
			ranges[n][2] = Math.max(ranges[2*n][2],ranges[2*n+1][2]);
			ranges[n][0] = ranges[2*n][0] + ranges[2*n+1][0];
		}

		public long minQuery(int n, int L, int R, int Lq, int Rq) {
			push(n,L,R);
			if (Lq <= L && R <= Rq) {
				return ranges[n][1];
			} else if (R < Lq || Rq < L || L==R) {
				return 1000000000000007L;
			} else {
				return Math.min(minQuery(2*n,L,(L+R)/2,Lq,Rq),minQuery(2*n+1,(L+R)/2+1,R,Lq,Rq));
			}
		}

		public long maxQuery(int n, int L, int R, int Lq, int Rq) {
			push(n,L,R);
			if (Lq <= L && R <= Rq) {
				return ranges[n][2];
			} else if (R < Lq || Rq < L || L==R) {
				return -1L;
			} else {
				return Math.max(maxQuery(2*n,L,(L+R)/2,Lq,Rq),maxQuery(2*n+1,(L+R)/2+1,R,Lq,Rq));
			}
		}

		public long sumQuery(int n, int L, int R, int Lq, int Rq) {
			push(n,L,R);
			if (Lq <= L && R <= Rq) {
				return ranges[n][0];
			} else if (R < Lq || Rq < L || L==R) {
				return 0L;
			} else {
				return (sumQuery(2*n,L,(L+R)/2,Lq,Rq) + sumQuery(2*n+1,(L+R)/2+1,R,Lq,Rq));
			}
		}

		public void push(int n, int L, int R) {
			ranges[n][1] += ranges[n][3];
			ranges[n][2] += ranges[n][3];
			ranges[n][0] += (R-L+1)*ranges[n][3];

			if (L < R) {
				ranges[2*n][3] += ranges[n][3];
				ranges[2*n+1][3] += ranges[n][3];
			}

			ranges[n][3] = 0;
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
        	  public int compare(int[] arr1, int[] arr2) {
				  return arr1[0]-arr2[0]; //ascending order
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
        	  public int compare(long[] arr1, long[] arr2) {
				  //return 0;
				  if (arr1[0] < arr2[0]) {
					  return -1;
				  } else if (arr1[0] > arr2[0]) {
					  return 1;
				  } else {
					  return 0;
				  }
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
