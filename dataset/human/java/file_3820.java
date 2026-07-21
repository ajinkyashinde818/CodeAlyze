import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		FastScanner fs = new FastScanner();
		String s = fs.next();
		sc.close();
		
//		ArrayList<Integer> sa = new ArrayList<Integer>();
//		for(int i=0; i<s.length(); i++){
//			sa.add(s.charAt(i) -97);
//		}
//		
//		int epos = sa.size() -1;
//		int ans = 0;
//		
//		for(int i=0; i<epos; i++){
//			int i1 = sa.get(i);
//			int i2 = sa.get(epos);
//			if(i1 != i2){
//				if(i1 != 23 && i2 != 23){
//					System.out.println("-1");
//					return;
//				}else if(i1 == 23){
//					sa.add(epos+1, 23);
//					ans++;
//					epos++;
//				}else if(i2 == 23){
//					sa.add(i, 23);
//					ans++;
//					epos++;
//				}
//			}
//			epos--;
//			if(ans > 100000){
//				System.out.println("-1");
//				return;
//			}
//		}
		
		char[] ca = s.toCharArray();
		
		int epos = s.length() -1;
		int ans = 0;
		
		for(int i=0; i<epos; i++){
			int i1 = ca[i] - 97;
			int i2 = ca[epos] - 97;
			if(i1 != i2){
				if(i1 != 23 && i2 != 23){
					System.out.println("-1");
					return;
				}else if(i1 == 23){
					ans++;
					epos++;
				}else if(i2 == 23){
					ans++;
					i--;
				}
			}
			epos--;
			if(ans > 100000){
				System.out.println("-1");
				return;
			}
		}
		
		System.out.println(ans);
		
//		int[] num = new int[26];
//		for(int i=0; i<s.length(); i++){
//			num[c[i]-97]++;
//		}
//		
//		int knum = 0;
//		int kpos;
//		for(int i=0; i<26; i++){
//			if(c[i] % 2 != 0){
//				knum++;
//				kpos = i;
//			}
//		}
//		
//		if(knum >= 2){
//			System.out.println("-1");
//			return;
//		}
//		
//		if(knum == 1){
//			
//		}
	}
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
}
