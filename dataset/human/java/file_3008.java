import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
//    	long l = System.currentTimeMillis();
        new Main().exec();
//    	long l2 = System.currentTimeMillis();
//    	System.out.println(l2 - l);
    }
    
    public void exec() throws IOException {
        InputUtil in = new InputUtil();
        PrintWriter out = new PrintWriter(System.out);
        int N = in.nextInt();
        int M = in.nextInt();
        int[] aToB = in.nextInt(new int[M*2]);
        HashSet<Integer> direct = new HashSet<Integer>(); 
        HashSet<Integer> reverse = new HashSet<Integer>(); 
        for(int i=0; i<M; i++){
        	if(aToB[i*2+0]==1)
        		direct.add(aToB[i*2+1]);
        	if(aToB[i*2+1]==N)
        		reverse.add(aToB[i*2+0]);
        }
        boolean judge=false;
        for(int d: direct){
        	if(reverse.contains(d))
        		judge=true;
        }
        out.println(judge?"POSSIBLE":"IMPOSSIBLE");
        out.flush();
    }
    
}

class InputUtil {
	//Static Fields
	private static final int BUFSIZ = 50000;
	
	//Fields
	protected InputStream in;
	private char[] buf = null;
	private int ptr = 0;
	private int max = -1;
	private BufferedReader br = null;
	
	//Constructors
	public InputUtil() {this(System.in,BUFSIZ);}
	public InputUtil(InputStream in, int bufsiz) {
		initBuf(bufsiz);
		initIn(in);
	}
	
	//Methods
	//Initializer
	protected void initIn(InputStream in) {br = new BufferedReader(new InputStreamReader(this.in = in));}
	protected void initBuf(int bufsiz) {buf = new char[bufsiz];}
	
	//buffer operation
	private void next() throws IOException {ptr++; readBuf();}
	private void readBuf() throws IOException {
		if(ptr >= max && br.ready()) {
			max = br.read(buf);
			ptr = 0;
		}
	}
	//Number Input Reader/Parser
	private boolean isNum(char b) {return '0' <= b && b <= '9'; }
	private boolean isMinus(char b) {return b=='-'; }

	private int _nextInt() throws IOException {
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
		return sign * res;
	}
	
	public int nextInt() throws IOException {
		readBuf();
		return _nextInt();
	}

	public int[] nextInt(int[] result) throws IOException {
		readBuf();
		for(int i=0; i<result.length; i++) {
			result[i] = _nextInt();
		}
		return result;
	}
	
	//Close 
	public void close() throws IOException {
		if(!this.in.equals(System.in)) 
			this.in.close();
	}

}
