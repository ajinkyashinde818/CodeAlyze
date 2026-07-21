import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		char[] s = sc.next().toCharArray();
		ArrayList<Character> nox = new ArrayList<>();
		for(int i=0; i<s.length; i++) {
			if(s[i] != 'x') nox.add(s[i]);
		}
		int i = 0;
		int j = nox.size()-1;
		while(i < j) {
			if(nox.get(i) != nox.get(j)) {
				System.out.println(-1);
				return;
			}
			i++;
			j--;
		}
		i = 0;
		j = s.length-1;
		int ans = 0;
		while(i < j) {
			if(s[i] == 'x' && s[j] == 'x') {
				i++;
				j--;
			} else if(s[i] == 'x') {
				ans++;
				i++;
			} else if(s[j] == 'x') {
				ans++;
				j--;
			} else {
				i++;
				j--;
			}
		}
		System.out.println(ans);
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
