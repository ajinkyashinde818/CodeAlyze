import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

 
public class Main {
	static final long MOD=1000000007;//998244353;
	public static void main(String[] args) {
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int N=sc.nextInt();
		int[] A=sc.nextIntArray(N);
		int[] B=sc.nextIntArray(N);
		int[] acount=new int[N+1];
		int[] bcount=new int[N+1];
		for (int i = 0; i < A.length; i++) {
			acount[A[i]]++;
			bcount[B[i]]++;
		}
		PriorityQueue<Pair> priorityQueue=new PriorityQueue<>();
		ArrayList<Integer> aarrayList=new ArrayList<>();
		ArrayList<Integer> bArrayList=new ArrayList<>();
		for (int i = 1; i < acount.length; i++) {
			if (acount[i]+bcount[i]>N) {
				System.out.println("No");
				return;
			}
			if (acount[i]==0&&bcount[i]==0) {
				continue;
			}else if(acount[i]==0){
				for (int j = 0; j < bcount[i]; j++) {
					bArrayList.add(i);
				}
			}else if (bcount[i]==0) {
				for (int j = 0; j < acount[i]; j++) {
					aarrayList.add(i);
				}
			}else {
				priorityQueue.add(new Pair(i, acount[i]+bcount[i]));
			}
		}
		ArrayList<Integer>[] arrayLis=new ArrayList[N+1];
		for (int i = 0; i < arrayLis.length; i++) {
			arrayLis[i]=new ArrayList<>();
		}
		while (priorityQueue.size()>1) {
			Pair p1=priorityQueue.poll();
			Pair p2=priorityQueue.poll();
			acount[p1.x]--;
			bcount[p2.x]--;
			arrayLis[p1.x].add(p2.x);
			if (acount[p1.x]>0) {
				priorityQueue.add(new Pair(p1.x, acount[p1.x]+bcount[p1.x]));
			}else {
				for (int i = 0; i < bcount[p1.x]; i++) {
					bArrayList.add(p1.x);
				}
			}
			if (bcount[p2.x]>0) {
				priorityQueue.add(new Pair(p2.x, acount[p2.x]+bcount[p2.x]));
			}else {
				for (int i = 0; i < acount[p2.x]; i++) {
					aarrayList.add(p2.x);
				}
			}
		}
		if (!priorityQueue.isEmpty()) {
			Pair pair=priorityQueue.poll();
			int c=0;
			for (int i = 0; i < acount[pair.x]; i++) {
				arrayLis[pair.x].add(bArrayList.get(c));
				c++;
			}
			for (int i = 0; i < aarrayList.size(); i++) {
				if (c>=bArrayList.size()) {
					arrayLis[aarrayList.get(i)].add(pair.x);
				}else {
					arrayLis[aarrayList.get(i)].add(bArrayList.get(c));
					c++;
				}
			}
		}else {
			for (int i = 0; i < aarrayList.size(); i++) {
				arrayLis[aarrayList.get(i)].add(bArrayList.get(i));
			}
		}
		out.println("Yes");
		for (int i = 0; i < arrayLis.length; i++) {
			for (int j: arrayLis[i]) {
				out.println(j);
			}
		}
		out.flush();
   	}
	static class Pair implements Comparable<Pair>{
    	public int x;
    	public int y;
    	public Pair(int x,int y) {
    		this.x=x;
    		this.y=y;
    	}
    	@Override
    	public boolean equals(Object obj) {
    		if(obj instanceof Pair) {
    			Pair other = (Pair) obj;
    			return other.x==this.x && other.y==this.y;
    		}
    		return false;
    	}//同値の定義
    	@Override
    	public int hashCode() {
    		return Objects.hash(this.x,this.y);
    	}//これ書かないと正しく動作しない（要　勉強）
    	@Override
    	public int compareTo( Pair p){
    		if (this.y<p.y) {
    			return 1;
    		}
    		else if (this.y>p.y) {
    			return -1;
    		}
    		else {
    			return 0;
    		}
    	}
    }
		static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
 
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
	}
