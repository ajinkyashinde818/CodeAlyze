import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
 
 
public class Main {
	
	public static void main(String[] args) throws IOException {
		Main m = new Main();
		//*
		m.input();
		m.solve();
		m.output();
		/*/
		m.debug();
		//*/
	}
	
	public void debug() {
	}
	
	//*
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	/*/
	InputUtil in = new InputUtil();
	//*/
	PrintWriter out = new PrintWriter(System.out);
	String s = null;
	int x,y;
	boolean ans=false;

	public void input() throws IOException {
		//*
		s = br.readLine();
		String[] tmp = br.readLine().split(" ");
		x = Integer.parseInt(tmp[0]);
		y = Integer.parseInt(tmp[1]);
		/*/
		N = in.nextInt();
		A = in.nextInt(new int[N]);
		//*/
	}
	
	public void solve() throws IOException {
		int movexCount = 0;
		int moveyCount = 0;
		List<Integer> movexCmd = new LinkedList<>();
		List<Integer> moveyCmd = new LinkedList<>();
		int fistMovex = 0;
		char[] sa = s.toCharArray();
		boolean dirx = true;
		boolean isFirstX = true;
		for(int i=0; i<sa.length; i++) {
			if(sa[i]=='F'){
				if(dirx){
					movexCount++;
				}else{
					moveyCount++;
				}
			}else{
				if(dirx){
					if(isFirstX){
						fistMovex = movexCount;
						isFirstX = false;
					}else{
						movexCmd.add(movexCount);
					}
					movexCount=0;
				}else{
					moveyCmd.add(moveyCount);
					moveyCount=0;
				}
				dirx = !dirx;
			}
		}
		
		if(dirx){
			if(isFirstX){
				fistMovex = movexCount;
			}else{
				movexCmd.add(movexCount);
			}
		}else{
			moveyCmd.add(moveyCount);
		}
		
		HashSet<Integer> xList = new HashSet<>();
		xList.add(fistMovex);
		HashSet<Integer> yList = new HashSet<>();
		yList.add(0);
		HashSet<Integer> xList2 = new HashSet<>();
		HashSet<Integer> yList2 = new HashSet<>();
		HashSet<Integer> tmp;
		
		for(int dx : movexCmd) {
			for(int x: xList) {
				xList2.add(x+dx);
				xList2.add(x-dx);
			}
			tmp = xList;
			xList = xList2;
			xList2 = tmp;
			xList2.clear();
			tmp = null;
		}
		boolean xisok = xList.contains(x);
		
		for(int dy : moveyCmd) {
			for(int y: yList) {
				yList2.add(y+dy);
				yList2.add(y-dy);
			}
			tmp = yList;
			yList = yList2;
			yList2 = tmp;
			yList2.clear();
			tmp = null;
		}
		boolean yisok = yList.contains(y);
		ans = xisok && yisok;
	}
	
	
	
	public void output() {
		out.println(ans?"Yes":"No");
		out.flush();
	}
}

//*
class InputUtil {
	//Static Fields
	private static final int BUFSIZ = 100000;
	
	//Fields
	protected InputStream in;
	private byte[] buf = null;
	private int ptr = 0;
	private int max = -1;
	private DataInputStream dis = null;
	//Constructors
	public InputUtil() {this(System.in,BUFSIZ);}
	public InputUtil(InputStream in, int bufsiz) {
		initBuf(bufsiz);
		initIn(in);
	}
	
	//Methods
	//Initializer
	protected void initIn(InputStream in) {dis = new DataInputStream(this.in = in);}
	protected void initBuf(int bufsiz) {buf = new byte[bufsiz];}
	
	//buffer operation
	private void next() throws IOException {ptr++; readBuf();}
	private void readBuf() throws IOException {
		if(ptr >= max && dis.available()>0) {
			if(max>0) Arrays.fill(buf,0,max,(byte)0);
			max = dis.read(buf);
			ptr = 0;
		}
	}
	
	//Number Input Reader/Parser
	private boolean isNum(byte b) {return '0' <= b && b <= '9'; }
	private boolean isMinus(byte b) {return b=='-'; }
 
	private int _nextInt() throws IOException {
		int sign = 1;
		int res = 0;
		byte c;
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
//*/
