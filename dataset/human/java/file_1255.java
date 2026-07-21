import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;


/**
 * --------------------------------------------------
 * Main Class
 * --------------------------------------------------
 */
public class Main {

	public void exec() throws IOException {
		InputUtil input = new InputUtil();
		PrintWriter out = new PrintWriter(System.out);
		int N = input.nextInt();
		int[] a = input.nextInt(new int[N]);
		out.println(calc_ans2(a,1,N-1));
		out.flush();
		input.close();
	}
	
	public long calc_ans2(int[] a, int min, int max) {
		long ans = -1;
		//calc min
		long S=0;
		long A=0;
		for(int i=0; i<a.length; i++) {
			if(i<min) {
				S+=a[i];
			}else{
				A+=a[i];
			}
		}
		//1ずつずらして計算
		ans = Math.abs(S-A);
		for(int i=min; i<a.length-1; i++) {
			S += a[i];
			A -= a[i];
			ans = Math.min(ans, Math.abs(S-A));
		}
		return ans;
	}
		

	public static void main(String[] args) throws IOException {
		new Main().exec();
	}
}

/**
 * --------------------------------------------------
 * Input Utility
 * --------------------------------------------------
 */
class InputUtil {
	//Static Fields
	private static final int BUFSIZ = 2200000;
	
	//Fields
	protected InputStream in;
	private char[] buf = null;
	private int ptr = 0;
	private int max = -1;
	private BufferedReader br = null;
	
	//Constructors
	public InputUtil() {this(System.in,BUFSIZ);}
	public InputUtil(int bufsiz) {this(System.in,bufsiz);}
	public InputUtil(InputStream in) {this(in,BUFSIZ);}
	public InputUtil(InputStream in, int bufsiz) {
		initBuf(bufsiz);
		initIn(in);
	}
	
	//Methods
	//Initializer
	protected void initIn(InputStream in) {br = new BufferedReader(new InputStreamReader(this.in = in));}
	protected void initBuf(int bufsiz) {buf = new char[bufsiz];}
	
	//String Input Reader/Parser
	private void readBuf() throws IOException {
		if(ptr >= max && br.ready()) {
			max = br.read(buf);
			ptr = 0;
		}
	}
	
	public BufferedReader getReader() {return br;}
	
	//Number Input Reader/Parser
	private boolean isNum(char b) {return '0' <= b && b <= '9'; }
	private boolean isMinus(char b) {return b=='-'; }
	private boolean isCrLf(char b) {return b == '\r' || b == '\n'; }
	private void next() throws IOException {ptr++; readBuf();}

	private void skipOneCrLf() throws IOException {
		char c = buf[ptr];
		if (isCrLf(c)) {
			ptr++;
			if (c == '\r') {
				readBuf();
				if (ptr < max && buf[ptr] == '\n') {
					ptr++;
				}
			}
		}
	}


	public String nextLine() throws IOException {
		StringBuilder sb = new StringBuilder();
		for(readBuf(); ptr < max ;readBuf()) {
			char c = buf[ptr];
			if(isCrLf(c)) {
				skipOneCrLf();
				break;
			}else{
				int strPtr = ptr++;
				int endPtr = -1;
				for(int i = ptr; i<max; i++) {
					if(isCrLf(buf[i])) {
						endPtr = i;
						break;
					}
				}
				if(endPtr == -1) endPtr = max;
				sb.append(String.valueOf(buf, strPtr, endPtr-strPtr)); 
				ptr = endPtr;
			}
		}
		return sb.toString();
	}
	
	public int nextInt() throws IOException {return nextInt(new int[1])[0];}
	public int[] nextInt(int[] result) throws IOException {
		readBuf();
		for(int i=0; i<result.length; i++) {
			int sign = 1;
			int res = 0;
			char c;
			while (!isNum(c=buf[ptr]) && !isMinus(c)) 
				next();
			if (isMinus(buf[ptr])) {
				sign = -1;
				next();
			}
			while (isNum(c=buf[ptr])) {
				res *= 10;
				res += c - '0' ;
				next();
			}
			next();
			result[i] = sign * res;
		}
		return result;
	}
	
	//Close 
	public void close() throws IOException {
		if(!this.in.equals(System.in)) 
			this.in.close();
	}

}
