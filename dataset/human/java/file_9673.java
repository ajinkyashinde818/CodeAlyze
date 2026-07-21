import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;


public class Main {
	
	public static void main(String[] args) throws IOException, InstantiationException, IllegalAccessException {
		new Main().exec();
	}
	
	public void exec() throws IOException, InstantiationException, IllegalAccessException {
		InputUtil in = new InputUtil();
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		BinaryTree bt = new BinaryTree(n);
		
		for(int i=0; i<n; i++){
			int id = in.nextInt();
			int leftId = in.nextInt();
			int rightId = in.nextInt();
			bt.setNode(id, leftId, rightId);
		}
		bt.refresh();
		out.print(bt);
		out.flush();
	}
}


class BinaryTree {
	
	private int[] left;
	private int[] right;
	private int[] parent;
	private int[] sibling;
	private int[] degree;
	private int[] depth;
	private int[] height;
	private int maxNodes;
	
	public BinaryTree(int maxNodes) {
		this.maxNodes=maxNodes;
		left = new int[maxNodes];
		right = new int[maxNodes];
		parent = new int[maxNodes];
		
		sibling = new int[maxNodes];
		degree = new int[maxNodes];
		depth = new int[maxNodes];
		height = new int[maxNodes];
		
		
		Arrays.fill(left, -1);
		Arrays.fill(right, -1);
		Arrays.fill(parent, -1);
		Arrays.fill(sibling, -1);
	}
	
	public void setNode(int id, int leftId, int rightId) {
		left[id] = leftId;
		if(leftId != -1) {
			parent[leftId] = id;
			sibling[leftId] = rightId;
		}
		right[id] = rightId;
		if(rightId != -1) {
			parent[rightId] = id;
			sibling[rightId] = leftId;
		}
	}
	
	public int getRootId() {
		int rootId = 0;
		while(parent[rootId] != -1)
			rootId = parent[rootId];
		return rootId;
	}
	
	public void refresh() throws InstantiationException, IllegalAccessException {
		refresh(getRootId(),0);
	}
	
	private int refresh(int id, int d) throws InstantiationException, IllegalAccessException {
		depth[id] = d;
		if(left[id] != -1) {
			degree[id] ++;
			height[id] = refresh(left[id], d+1);
		}
		if(right[id] != -1) {
			degree[id] ++;
			height[id] = Math.max(height[id], refresh(right[id], d+1));
		}
		return height[id]+1;
	}

	
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<maxNodes; i++) {
			sb.append("node ").append(i)
				.append(": parent = ").append(parent[i])
				.append(", sibling = ").append(sibling[i])
				.append(", degree = ").append(degree[i])
				.append(", depth = ").append(depth[i])
				.append(", height = ").append(height[i])
				.append(", ");

			if(parent[i] == -1)
				sb.append("root");
			else if(left[i] == -1 && right[i] == -1)
				sb.append("leaf");
			else 
				sb.append("internal node");
			
			sb.append(System.lineSeparator());
		}
		return sb.toString();
	}
}


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
