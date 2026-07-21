import java.io.*; 
import java.math.*;
import java.util.*;
 
public class Main {
	static final long MOD = 998244353;
	//static final long MOD = 1000000007;
	static boolean[] visited;
    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        int[] dish = new int[N];
        for (int i = 0; i < N; i++)
        	dish[i] = sc.nextInt()-1;
        int[] B = new int[N];
        for (int i = 0; i < N; i++)
        	B[i] = sc.nextInt();
        int[] C = new int[N-1];
        for (int i = 0; i < N-1; i++)
        	C[i] = sc.nextInt();
        int ans = 0;
        int lastDish = 10000000;
        for (int i = 0; i < N; i++) {
        	if (lastDish+1==dish[i]) {
        		ans += C[lastDish];
        	}
        	ans += B[dish[i]];
        	lastDish = dish[i];
        }
        System.out.println(ans);
    }
    
    public static void recursiveDFS(Node root) {
    	visited[root.n] = true;
    	//recStack[root.n] = true;
    	for (Node child: root.children) {
    		if (! visited[child.n]) {
    			visited[child.n] = true;
    			recursiveDFS(child);
    		} //else if (recStack[child.n]) {
    			//coloring[root.n][child.n] = true;
    			//colors = 2;
    		//}
    	}
    	//recStack[root.n] = false;
    }
    
    public static int[] sort(int[] array) {
    	//Sort an array (immune to quicksort TLE)
		Random rgen = new Random();
		for (int i = 0; i< array.length; i++) {
		    int randomPosition = rgen.nextInt(array.length);
		    int temp = array[i];
		    array[i] = array[randomPosition];
		    array[randomPosition] = temp;
		}
		Arrays.sort(array);

		return array;
	}
    
    public static int[][] sort(int[][] array) {
    	//Sort an array (immune to quicksort TLE)
		Random rgen = new Random();
		for (int i = 0; i< array.length; i++) {
		    int randomPosition = rgen.nextInt(array.length);
		    int[] temp = array[i];
		    array[i] = array[randomPosition];
		    array[randomPosition] = temp;
		}
		Arrays.sort(array, new Comparator<int[]>() {
			  @Override
			  public int compare(int[] arr1, int[] arr2) {
				  //Ascending order.
				  if (arr1[1]!=arr2[1])
					  return arr1[1]-arr2[1];
				  else
					  return arr2[0]-arr1[0];
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
  
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() { 
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

class Node {
	public HashSet<Node> children;
	public int n;
	
	public Node(int n) {
		this.n = n;
		children = new HashSet<Node>();
	}
	
	public void addChild(Node node) {
		children.add(node);
	}
	
	public void removeChild(Node node) {
		children.remove(node);
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return n;
	}

	@Override
	public boolean equals(Object obj) {
		if (! (obj instanceof Node)) {
			return false;
		} else {
			Node node = (Node) obj;
			return (n == node.n);
		}
	}
	
	public String toString() {
		return (this.n+1)+"";
	}
}

class BinaryIndexedTree {
	  public long[] arr;
 
	  public BinaryIndexedTree (int N) {
	    arr = new long[N+1];
	    arr[0] = 0;
	  }
 
	  //add k to the i-th element.
	  public void add(long k, int i) {
	    int node = i+1;
	    while (node < arr.length) {
	      arr[node] += k;
	      node += node & (-node);
	    }
	  }
 
	  //sum up the elements from input[s_i] to input[e_i], from [s_i,e_i).
	  public long sum(int s_i, int e_i) {
	    return sum(e_i) - sum(s_i);
	  }
 
	  public long sum(int i) {
	    long total = 0;
	    int node = i;
	    while (node > 0) {
	      total += arr[node];
	      node -= node & (-node);
	    }
	    return total;
	  }
}

class DSU {
	public int N;
	public int[] parent;
	public int[] rank;
	public int count;
	
	public DSU(int numNodes) {
		N = numNodes;
	    parent = new int[N];
	    rank = new int[N];
	    for (int i = 0; i < N; i++) {
	    	parent[i] = i;
	    	rank[i] = 1;
	    }
	    count = numNodes;
	}
	
	public boolean isConnected(int p, int q) {
	    return root(p) == root(q);
	}
	
	public int root(int p) {
		while (p != parent[p])
			p = parent[p];
	    return p;
	}
	
	//only connect p and q if they are disjointed.
	public void connect(int p, int q) {
		int rootP = root(p);
	    int rootQ = root(q);
	    if (rank[rootP] >= rank[rootQ]) {
	    	parent[rootQ] = rootP;
	    	rank[rootP] += rank[rootQ];
	    } else if (rank[rootQ] > rank[rootP]) {
	    	parent[rootP] = rootQ;
	    	rank[rootQ] += rank[rootP];
	    }
	    count--;
	}
}
