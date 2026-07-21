import java.util.*;
import java.io.*;
import java.math.BigDecimal;
import java.awt.geom.*;
import static java.util.Arrays.*;
import static java.lang.Math.*;

public class Main{

    static final Reader sc = new Reader();
    static final PrintWriter out = new PrintWriter(System.out,false);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
        	String str1 = sc.next();
        	String str2 = sc.next();
        	int ans1 = 0;
        	int ans2 = 0;
        	int count1 = 0;
        	int count2 = 0;
        	int length1 = str1.length();
        	int length2 = str2.length();
        	int now = 1;
        	while(count1<length1){
        		if(str1.charAt(count1)=='m'){
        			ans1 += now * 1000;
        			now = 1; 
        		}
        		else if(str1.charAt(count1)=='c'){
        			ans1 += now * 100;
        			now = 1;
        		}
        		else if(str1.charAt(count1)=='x'){
        			ans1 += now * 10;
        			now = 1;
        		}
        		else if(str1.charAt(count1)=='i'){
        			ans1 += now;
        			now = 1;
        		}
        		else{
        			now = (int)str1.charAt(count1) - (int)'0'; 
        		}
        		count1++;
        	}
        	now = 1;
        	while(count2<length2){
        		if(str2.charAt(count2)=='m'){
        			ans2 += now * 1000;
        			now = 1; 
        		}
        		else if(str2.charAt(count2)=='c'){
        			ans2 += now * 100;
        			now = 1;
        		}
        		else if(str2.charAt(count2)=='x'){
        			ans2 += now * 10;
        			now = 1;
        		}
        		else if(str2.charAt(count2)=='i'){
        			ans2 += now;
        			now = 1;
        		}
        		else{
        			now = (int)str2.charAt(count2) - (int)'0'; 
        		}
        		count2++;
        	}
        	int ans = ans1 + ans2;
        	int check = 0;
        	while(ans != 0){
        		check = String.valueOf(ans).length();
        		int x = (int)Math.pow(10,check-1);
        		if(ans/x>1){
        			out.print(ans/x);	
        		}
        		if(check==4){
        			out.print("m");
        		}
        		else if(check==3){
        			out.print("c");
        		}
        		else if(check==2){
        			out.print("x");
        		}
        		else{
        			out.print("i");
        		}
        		ans -= (ans/x)*x;
        	}
        	out.println();
        	out.flush();
        }
        sc.close();
        out.close();
    }

    static void trace(Object... o) { System.out.println(Arrays.deepToString(o));}
}

class Reader {
    private final InputStream sc;
    private final byte[] buf = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    public Reader() { this(System.in);}
    public Reader(InputStream source) { this.sc = source;}

    private boolean hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        try{
            buflen = sc

.read(buf);
        }catch (IOException e) {e.printStackTrace();}
        if (buflen <= 0) return false;
        return true;
    }

    private int readByte() { if (hasNextByte()) return buf[ptr++]; else return -1;}

    private boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}

    private void skip() { while(hasNextByte() && !isPrintableChar(buf[ptr])) ptr++;}

    public boolean hasNext() {skip(); return hasNextByte();}

    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        boolean minus = false;
        long num = readByte();

        if(num == '-'){
            num = 0;
            minus = true;
        }else if (num < '0' || '9' < num){
            throw new NumberFormatException();
        }else{
            num -= '0';
        }
        
        while(true){
            int b = readByte();
            if('0' <= b && b <= '9')
                num = num * 10 + (b - '0');
            else if(b == -1 || !isPrintableChar(b))
                return minus ? -num : num;
            else
                throw new NoSuchElementException();
        }
    }

    public int nextInt() {
        long num = nextLong();
        if (num < Integer.MIN_VALUE || Integer.MAX_VALUE < num)
            throw new NumberFormatException();
        return (int)num;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public char nextChar() {
        if (!hasNext()) throw new NoSuchElementException();
        return (char)readByte();
    }

    public String nextLine() {
        while (hasNextByte() && (buf[ptr] == '\n' || buf[ptr] == '\r')) ptr++;
        if (!hasNextByte()) throw new NoSuchElementException();

        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (b != '\n' && b != '\r') {
            sb.appendCodePoint(b);
            b = readByte();
        }

        return sb.toString();
    }

    public int[] nextIntArray(int n) {
        int[] res = new int[n];
        for (int i=0; i<n; i++) res[i] = nextInt();
        return res;
    }

    public char[] nextCharArray(int n) {
        char[] res = new char[n];
        for (int i=0; i<n; i++) res[i] = nextChar();
        return res;
    }

    public void close() {try{ sc.close();}catch(IOException e){ e.printStackTrace();}};
}
