import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static long mod = 1000000007;

    public static void main(String[] args) {
    	int N = sc.nextInt();
    	int M = sc.nextInt();
    	boolean[] broken = new boolean[N+3];
    	long[] frac = new long[200001];
    	frac[0] = 1;
    	for(int i=1; i<=200000; i++) {
    		frac[i] = frac[i-1] * i % mod;
    	}
    	for(int i=0; i<M; i++) {
    		broken[sc.nextInt()] = true;
    	}
    	broken[N+1] = true;
    	broken[N+2] = false;
    	long ans = 1;
		int notbrokennum = 0;
    	int i = 0;
    	while(i <= N) {
    		if(!broken[i+1]) {
    			notbrokennum++;
    			i++;
    		} else {
    			if(broken[i+2]) {
    				System.out.println(0);
    				return;
    			}
    			long pattern = 0;
    			int tmp = 0;
    			while(notbrokennum >= tmp) {
    				pattern = (pattern + (frac[notbrokennum] % mod * power(frac[tmp], mod-2) % mod * power(frac[notbrokennum - tmp], mod-2) % mod)) % mod;
    				notbrokennum--;
    				tmp++;
    			}
    			ans = ans * pattern % mod;
    			i += 2;
    			notbrokennum = 0;
    		}
    	}
    	System.out.println(ans);
    }

    static long power(long m , long n){
    	if(n == 0) {
    		return 1;
    	}else if(n == 1){
            return m;
        }else if(n % 2 == 0){
            long s = power(m, n/2);
            return ( (s % mod) * (s % mod) ) % mod;
        }else{
            return ( (m % mod) * (power(m, n-1) % mod) ) % mod;
        }
    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
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
            return Long.parseLong(next());
        }
        public int nextInt(){
            return Integer.parseInt(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}
