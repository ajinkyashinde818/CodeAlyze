import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}

class Main {
	public static void main(String[] args) {
		new Main().run();
	}
	
	void run() {
		FastScanner sc=new FastScanner();
		int N=sc.nextInt();
		int[] A=new int[N];
		int[] B=new int[N];
		int[] ca=new int[N];
		int[] cb=new int[N];
		for (int i=0;i<N;++i) {
			A[i]=sc.nextInt()-1;
			ca[A[i]]++;
		}
		for (int i=0;i<N;++i) {
			B[i]=sc.nextInt()-1;
			cb[B[i]]++;
		}
		class P implements Comparable<P>{
			int val;
			int num;
			int co;
			public P(int val,int num,int co) {
				this.val=val;
				this.num=num;
				this.co=co;
			}
			public int compareTo(P o) {
				return -Integer.compare(co, o.co);
			};
		}
		ArrayDeque<Integer>[] ans=new ArrayDeque[N];
		for (int i=0;i<ans.length;++i) ans[i]=new ArrayDeque<>();
		PriorityQueue<P> aq=new PriorityQueue<>();
		PriorityQueue<P> bq=new PriorityQueue<>();
		for (int i=0;i<N;++i) {
			if (ca[i]>0) aq.add(new P(i,ca[i],Math.min(ca[i], cb[i])));
			if (cb[i]>0) bq.add(new P(i,cb[i],Math.min(ca[i], cb[i])));
		}
		while (!aq.isEmpty()) {
			P pa0=aq.poll();
			if (pa0.co!=Math.min(ca[pa0.val], cb[pa0.val])) {
				pa0.co =Math.min(ca[pa0.val], cb[pa0.val]);
				aq.add(pa0);
				continue;
			}
			P pb0=bq.poll();
			if (pb0.co!=Math.min(ca[pb0.val], cb[pb0.val])) {
				pb0.co =Math.min(ca[pb0.val], cb[pb0.val]);
				aq.add(pa0);
				bq.add(pb0);
				continue;
			}
			if (pa0.val==pb0.val&&bq.isEmpty()) {
				System.out.println("No");
				return;
			}
			P b;
			if (pa0.val!=pb0.val) {
				b=pb0;
			} else {
				b=bq.poll();
				bq.add(pb0);
				if (b.co!=Math.min(ca[b.val], cb[b.val])) {
					b.co =Math.min(ca[b.val], cb[b.val]);
					bq.add(b);
					aq.add(pa0);
					continue;
				}
			}
			ans[pa0.val].addLast(b.val);
			pa0.num--;
			b.num--;
			ca[pa0.val]=pa0.num;
			ca[b.val]=b.num;
			pa0.co =Math.min(ca[pa0.val], cb[pa0.val]);
			b.co =Math.min(ca[b.val], cb[b.val]);
			if (pa0.num>0) aq.add(pa0);
			if (b.num>0) bq.add(b);
		}
		System.out.println("Yes");
		PrintWriter pw=new PrintWriter(System.out);
		for (int i=0;i<N;++i) {
			pw.print((ans[A[i]].poll()+1)+(i==N-1?"\n":" "));
		}
		pw.flush();
	}
	
	void tr(Object...objects) {System.out.println(Arrays.deepToString(objects));}
}
