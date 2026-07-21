import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;

public class Main{
	public static void main(String[]$) throws IOException{
		new Main().solve();
	}
	static FastScanner s=new FastScanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static int gInt() throws IOException{return s.nextInt();}
	static long gLong() throws IOException{return s.nextLong();}
	static long gDouble() throws IOException{return s.nextLong();}

	private void solve() throws IOException{
		char[]v;
		{
			String in=s.next();
			if(!isPalindrome(in.replaceAll("x",""))) {
				System.out.println(-1);
				return;
			}
			v=in.toCharArray();
		}
		int l=0,r=v.length-1,c=0;

		for(;l<r;++l) {
			if(v[l]==v[r]) {
				--r;
			}else if(v[l]=='x'&&v[r]!='x') {
				++c;
			}else if(v[l]!='x'&&v[r]=='x') {
				--l;
				--r;
				++c;
			}
		}

		System.out.println(c);
	}

	boolean isPalindrome(String v) {
		for(int i=0;i<v.length();++i) {
			if(v.charAt(i)!=v.charAt(v.length()-1-i))
				return false;
		}
		return true;
	}

	static void yesno(boolean f) {
		yesno(f,"YES","NO");
	}
	static void yesno(boolean f,String yes,String no) {
		System.out.println(f?yes:no);
	}
}
class FastScanner{
	private final BufferedInputStream	in;
	private static final int			bufSize	=1<<16;
	private final byte					buf[]	=new byte[bufSize];
	private int							i		=bufSize;
	private int							k		=bufSize;
	private final StringBuilder			str		=new StringBuilder();

	FastScanner(InputStream in){
		this.in=new BufferedInputStream(in,bufSize);
	}
	int nextInt() throws IOException{
		return (int)nextLong();
	}
	long nextLong() throws IOException{
		int c;
		long x=0;
		boolean sign=true;
		while((c=nextChar())<=32)
			;
		if(c=='-'){
			sign=false;
			c=nextChar();
		}
		if(c=='+'){
			c=nextChar();
		}
		while(c>='0'){
			x=x*10+(c-'0');
			c=nextChar();
		}
		return sign?x:-x;
	}
	int nextChar() throws IOException{
		if(i==k){
			k=in.read(buf,0,bufSize);
			i=0;
		}
		return i>=k?-1:buf[i++];
	}
	String next() throws IOException{
		int c;
		str.setLength(0);
		while((c=nextChar())<=32&&c!=-1)
			;
		if(c==-1){
			return null;
		}
		while(c>32){
			str.append((char)c);
			c=nextChar();
		}
		return str.toString();
	}
	String nextLine() throws IOException{
		int c;
		str.setLength(0);
		while((c=nextChar())<=32&&c!=-1)
			;
		if(c==-1){
			return null;
		}
		while(c!='\n'){
			str.append((char)c);
			c=nextChar();
		}
		return str.toString();
	}
}
