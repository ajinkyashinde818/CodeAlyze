import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}
	
	void run() {
		FastScanner sc=new FastScanner();
		String str=sc.next();
		int Q=sc.nextInt();
		ArrayDeque<String> dq=new ArrayDeque<>();
		dq.add(str);
		boolean flip=false;
		for(int q=0;q<Q;++q) {
			int t=sc.nextInt();
			if(t==1)flip=!flip;
			else {
				int f=sc.nextInt();
				String c=sc.next();
				if(f==1) {
					if(flip)dq.addLast(c);
					else dq.addFirst(c);
				}else {
					if(!flip)dq.addLast(c);
					else dq.addFirst(c);
				}
			}
		}
		PrintWriter pw=new PrintWriter(System.out);
		if(!flip) {
			while(!dq.isEmpty()) {
				pw.print(dq.pollFirst());
			}
			pw.println();
		}else {
			while(!dq.isEmpty()) {
				char[] cs=dq.pollLast().toCharArray();
				int s=0,t=cs.length-1;
				while(s<t) {
					cs[s]^=cs[t];cs[t]^=cs[s];cs[s]^=cs[t];
					++s;
					--t;
				}
				pw.print(String.valueOf(cs));
			}
			pw.println();
		}
		pw.close();
	}
	
	void tr(Object...objects) {System.out.println(Arrays.deepToString(objects));}
}


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
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
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
    
    int nextInt() {
    	return (int)nextLong();
    }
}
