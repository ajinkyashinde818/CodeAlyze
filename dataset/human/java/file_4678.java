import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

class Main {
	public static void main(String[] args) throws Exception {
		new Main().run();
	}
	
	long solve(int[] a) {
		int n=a.length;
		long[][] dp=new long[n][10];//0,1
		for(int i=0;i<n;++i) {
			for(int j=0;j<dp[i].length;++j)dp[i][j]=Integer.MAX_VALUE/3;
		}
		for(int i=0;i<n;++i) {
			for(int pre=0;pre<=1;++pre) {//a[i]=10*pre+x-y
				for(int x=0;x<=9;++x) {
					for(int y=0;y<=9;++y) {
						int ne=10*pre+x-y-a[i];
						if(Math.abs(ne)>=2)continue;
						if(ne>9)continue;
						if(ne<0)break;
						dp[i][ne]=Math.min(dp[i][ne], (i>0?dp[i-1][pre]:(pre==0?0:Integer.MAX_VALUE/3))+x+y);
					}
				}
			}
		}
		return dp[n-1][0];
	}
	
	void run() {
		Scanner sc=new Scanner();
		//x-N=y
		//N=x-y
		char[] cs=sc.next().toCharArray();
		int[] a=new int[cs.length+1];
		for(int i=1;i<a.length;++i) {
			a[i]=(int)(cs[i-1]-'0');
		}
		System.out.println(solve(a));
	}
	
	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
		
	}

}

class Scanner {
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
