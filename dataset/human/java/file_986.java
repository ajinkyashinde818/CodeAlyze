import java.io.*;
import java.util.*;

public class Main implements Runnable{
	public static void main (String[] args) {new Thread(null, new Main(), "_cf", 1 << 28).start();}

	public void run() {
		DeoxysS fs = new DeoxysS();
		PrintWriter out = new PrintWriter(System.out);
		System.err.println("Go!");

		int N = fs.nextInt();
		long C = fs.nextLong();
		long[][] data = new long[N + 1][2];
		data[0][0] = data[0][1] = 0;
		for(int i = 1; i <= N; i++) {
			data[i][0] = fs.nextLong();
			data[i][1] = fs.nextLong();
		}
		
		Arrays.sort(data, (a, b) -> Long.compare(a[0], b[0]));
//		for(long[] ll : data) System.out.println(Arrays.toString(ll));
		
		long[] pre = new long[N + 1];
		for(int i = 1; i <= N; i++) pre[i] = pre[i - 1] + data[i][1];

		long[] vsRight = new long[N + 1], vsLeft = new long[N + 1];
		long walkRight = 0;
		long walkLeft = 0;
		long cur = 0, lastWalk = 0;
		for(int i = 1; i <= N; i++) {
			cur -= Math.abs(data[i][0] - lastWalk);
			cur += data[i][1];
			walkRight = Math.max(walkRight, cur);
			vsRight[i] = cur;
			lastWalk = data[i][0];
		}
		
		cur = lastWalk = 0; lastWalk = C;
		for(int i = N; i > 0; i--) {
			cur -= Math.abs(data[i][0] - lastWalk);
			cur += data[i][1];
			walkLeft = Math.max(walkLeft, cur);
			vsLeft[i] = cur;
			lastWalk = data[i][0];
		}
		
		BIT bit = new BIT(N + 1);
		for(int i = 1; i <= N; i++) {
			bit.update(i, vsRight[i]);
		}
		
		lastWalk = C;
		long res = Math.max(walkLeft, walkRight);
		long dist = 0;
		for(int i = N; i > 0; i--) {
			dist += -(lastWalk - data[i][0]);
//			dist *= 2;
			dist += data[i][1];
			res = Math.max(res, dist - (C - data[i][0]) + bit.sum(i - 1));
			lastWalk = data[i][0]; 
		}
		
		bit = new BIT(N + 1);
		for(int i = N, c = 1; i > 0; i--) {
			bit.update(c++, vsLeft[i]);
		}
		
//		for(int i = 1; i <= N; i++) System.out.println(i + " " + bit.sum(i));
		
		lastWalk = 0;
		dist = 0;
		for(int i = 1; i <= N; i++) {
			dist += -(data[i][0] - lastWalk);
			dist += data[i][1];
//			System.out.println(dist + " " + (data[i][0]) + " " + (i + 1) + " " + bit.sum(i+1)) ;
			res = Math.max(res, dist - data[i][0] + bit.sum(N - i));
			lastWalk = data[i][0];
		}
		
		
		out.println(res);
		
		out.close();
	}
	
	class BIT {
		
		long[] bit;
		int n;
		
		public BIT(int a) {
			n = a + 1;
			bit = new long[n];
		}
		
		//Remember that when querying a sum to query the 1-based index of the value.
		
		void update (int index, long val) {
			while(index < n) {
				bit[index] = Math.max(bit[index], val);
				index += (index & (-index));
			}
		}
		
		long sum (int index) {
			long sum = 0;
			while(index > 0) {
				sum = Math.max(sum, bit[index]);
				index -= (index & (-index));
			}
			return sum;
		}
	}

	
	long query(long[] pre, int left, int right) {
		long res = pre[right];
		if(left > 0) res -= pre[left - 1];
		return res;
	}
	
	class DeoxysS {
		public int BS = 1<<16;
		public char NC = (char)0;
		byte[] buf = new byte[BS];
		int bId = 0, size = 0;
		char c = NC;
		double num = 1;
		BufferedInputStream in;

		public DeoxysS() {
			in = new BufferedInputStream(System.in, BS);
		}

		public DeoxysS(String s) throws FileNotFoundException {
			in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
		}

		public char nextChar(){
			while(bId==size) {
				try {
					size = in.read(buf);
				}catch(Exception e) {
					return NC;
				}                
				if(size==-1)return NC;
				bId=0;
			}
			return (char)buf[bId++];
		}

		public int nextInt() {
			return (int)nextLong();
		}

		public long nextLong() {
			num=1;
			boolean neg = false;
			if(c==NC)c=nextChar();
			for(;(c<'0' || c>'9'); c = nextChar()) {
				if(c=='-')neg=true;
			}
			long res = 0;
			for(; c>='0' && c <='9'; c=nextChar()) {
				res = (res<<3)+(res<<1)+c-'0';
				num*=10;
			}
			return neg?-res:res;
		}

		public double nextDouble() {
			double cur = nextLong();
			return c!='.' ? cur:cur+nextLong()/num;
		}

		public String next() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c>32) {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public String nextLine() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c!='\n') {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public boolean hasNext() {
			if(c>32)return true;
			while(true) {
				c=nextChar();
				if(c==NC)return false;
				else if(c>32)return true;
			}
		}
		
		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for(int i = 0; i < n; i++) res[i] = nextInt();
			return res;
		}
		
	}

}
