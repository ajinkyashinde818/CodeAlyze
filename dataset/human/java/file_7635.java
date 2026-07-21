import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
	public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
	public static void main(String sp[])throws IOException{
		Scanner sc = new Scanner(System.in);
		//FastReader sc = new FastReader();
		int n = sc.nextInt();
		long k = sc.nextLong();
		ArrayList<Integer> al = new ArrayList<>();
		al.add(0);
		for(int i=1;i<=n;i++)
			al.add(sc.nextInt());
		HashMap<Integer,Integer> hm = new LinkedHashMap<>();
		int val = 1;
		int gh = 0;
		for(int i=0;;i++){
			int temp = al.get(val);
			if(hm.containsKey(temp)){
				gh = hm.get(temp);
				break;
			}else hm.put(temp,i);
			val = temp;
		}
		
		ArrayList<Integer> key = new ArrayList<>(hm.keySet());
		int siz = key.size();
		if(k<=siz){
			System.out.println(key.get((int)k-1));
			return;
		}
		int loop = siz-gh;
		int h = siz-loop;
		k-=(h);
		long mod = k%(long)(siz-h);
		int o = (int)mod;
		if(o==0)
			System.out.println(key.get(siz-1));
		else 
			System.out.println(key.get(h+o-1));
	}
	
	
	
	static ArrayList<ArrayList<Integer>> printSubsequences(int n, int arr[]) 
    { 
        /* Number of subsequences is (2**n -1)*/
		ArrayList<ArrayList<Integer>> temp = new ArrayList<>();
        int opsize = (int)Math.pow(2, n); 
       
        /* Run from counter 000..1 to 111..1*/
        for (int counter = 1; counter < opsize; counter++) 
        { 
			ArrayList<Integer> al = new ArrayList<>();
            for (int j = 0; j < n; j++) 
            { 
                /* Check if jth bit in the counter is set 
                    If set then print jth element from arr[] */
                if (BigInteger.valueOf(counter).testBit(j)) 
                    al.add(arr[j]); 
            }  
			if(al.size()!=0)
				temp.add(al);
        } 
		return temp;
    } 
	
	public static class pair{
		int x;
		int y;
	}
	
	public static class comp implements Comparator<pair>{
		public int compare(pair o1, pair o2){
			if(o1.x==o2.x){
				return o1.y-o2.y;
			}
			return o1.x-o2.x;
		}
	}
	
	
	
	static HashMap<Integer,Integer> visited = new HashMap<>();
	
	static class Node{
		int node;
		int d;
		ArrayList<Integer> al = new ArrayList<>();	
	}
	

	static long gcd(long a, long b) 
    { 
      if (b == 0) 
        return a; 
      return gcd(b, a % b);  
    }
	
		
	static class FastReader 
		{ 
		final private int BUFFER_SIZE = 1 << 16; 
		private DataInputStream din; 
		private byte[] buffer; 
		private int bufferPointer, bytesRead; 
  
		public FastReader() 
		{ 
			din = new DataInputStream(System.in); 
			buffer = new byte[BUFFER_SIZE]; 
			bufferPointer = bytesRead = 0; 
		} 
  
		public FastReader(String file_name) throws IOException 
		{ 
			din = new DataInputStream(new FileInputStream(file_name)); 
			buffer = new byte[BUFFER_SIZE]; 
			bufferPointer = bytesRead = 0; 
		} 
  
		public String readLine() throws IOException 
		{ 
			byte[] buf = new byte[64]; // line length 
			int cnt = 0, c; 
			while ((c = read()) != -1) 
			{ 
				if (c == '\n') 
					break; 
				buf[cnt++] = (byte) c; 
			} 
			return new String(buf, 0, cnt); 
		} 
  
		public int nextInt() throws IOException 
		{ 
			int ret = 0; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
			do
			{ 
				ret = ret * 10 + c - '0'; 
			}  while ((c = read()) >= '0' && c <= '9'); 
  
			if (neg) 
				return -ret; 
			return ret; 
		} 
  
		public long nextLong() throws IOException 
		{ 
			long ret = 0; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
			do { 
				ret = ret * 10 + c - '0'; 
			} 
			while ((c = read()) >= '0' && c <= '9'); 
			if (neg) 
				return -ret; 
			return ret; 
		} 
  
		public double nextDouble() throws IOException 
		{ 
			double ret = 0, div = 1; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
  
			do { 
				ret = ret * 10 + c - '0'; 
			} 
			while ((c = read()) >= '0' && c <= '9'); 
  
			if (c == '.') 
			{ 
				while ((c = read()) >= '0' && c <= '9') 
				{ 
					ret += (c - '0') / (div *= 10); 
				} 
			} 
  
			if (neg) 
				return -ret; 
			return ret; 
		} 
  
		private void fillBuffer() throws IOException 
		{ 
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
			if (bytesRead == -1) 
				buffer[0] = -1; 
		} 
  
		private byte read() throws IOException 
		{ 
			if (bufferPointer == bytesRead) 
				fillBuffer(); 
			return buffer[bufferPointer++]; 
		} 
  
		public void close() throws IOException 
		{ 
			if (din == null) 
				return; 
			din.close(); 
		} 
	} 
}
