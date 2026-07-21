import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		ContestScanner scan = new ContestScanner();

		final int n = scan.nextInt();
		final Node[] nodes = new Node[n];

		for(int i=0; i < n; i++)
		{
			final int id = scan.nextInt();
			final int l = scan.nextInt();
			final int r = scan.nextInt();

			nodes[i] = new Node(id, l, r);
		}

		(new Solve(n, nodes)).solve();
	}
}
class Solve {
	private final int n;
	private final Node[] nodes;

	public Solve(final int n, final Node[] nodes)
	{
		this.n = n;
		this.nodes = nodes;
	}

	public void solve()
	{
		Node[] nodeMap = new Node[n];
		int[] childMap = new int[n];
		Arrays.fill(childMap, -1);

		for(int i=0; i < n; i++)
		{
			Node n = nodes[i];

			nodeMap[n.id] = n;

			if(n.l != -1) childMap[n.l] = n.id;
			if(n.r != -1) childMap[n.r] = n.id;

		}

		for(Node n: nodes)
		{
			n.tryLink(nodeMap, childMap);
		}

		StringBuilder sb = new StringBuilder();

		for(Node n: nodeMap)
		{
			sb.append(n.toString() + "\n");
		}

		System.out.print(sb.toString());
	}
}
class Node {
	public final int id;
	public final int l;
	public final int r;
	private int parent;
	private int sibling;
	private int degree;
	private int depth;
	private int height;

	public Node(final int id, final int l, final int r)
	{
		this.id = id;
		this.l = l;
		this.r = r;
		this.degree = (this.l != -1 ? 1 : 0) + (this.r != -1 ? 1 : 0);
		this.sibling = -1;
		this.parent = -2;
		this.depth = 0;
		this.height = 0;
	}

	public void tryLink(Node[] nodeMap, int[] childMap)
	{
		if(this.parent == -2 && childMap[this.id] == -1)
		{
			this.height = linkNodes(0, -1, nodeMap, -1);
		}
	}

	private int linkNodes(final int depth, final int parent, Node[] nodeMap, int sibling)
	{
		this.depth = depth;
		this.parent = parent;
		this.sibling = sibling;

		int height = 0;

		if(this.l != -1)
		{
			Node n = nodeMap[this.l];
			height = n.linkNodes(this.depth + 1, this.id, nodeMap, this.r) + 1;
		}

		if(this.r != -1)
		{
			Node n = nodeMap[this.r];
			height = Math.max(height, n.linkNodes(this.depth + 1, this.id, nodeMap, this.l) + 1);
		}

		this.height = height;

		return height;
	}

	public String getTypeString()
	{
		if(this.parent == -1) return "root";
		else if(this.degree > 0) return "internal node";
		else return "leaf";
	}

	@Override
	public String toString()
	{
		return String.format(
				"node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s",
				this.id, this.parent, this.sibling, this.degree, this.depth, this.height, this.getTypeString());
	}
}
class ContestScanner {
	BufferedReader reader;
	String[] line;
	int index;
	public ContestScanner() {
		reader = new BufferedReader(new InputStreamReader(System.in));
	}

	public ContestScanner(String filename) throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(filename)));
	}

	public static interface ICreator<T> {
		public T createFromToken(final ContestScanner scanner) throws IOException;
	}

	public static interface IArrayInitializer {
		public void initialize(final ContestScanner scanner, final int i) throws IOException;
	}

	public static interface IObjectInitializer<T> {
		public T initialValue(final ContestScanner scanner);
	}

	public static class ObjectArrayInitializer<T> implements IArrayInitializer {
		protected T[] arr;
		protected final IObjectInitializer<T> initializer;

		private ObjectArrayInitializer(T[] arr, final IObjectInitializer<T> initializer)
		{
			this.arr = arr;
			this.initializer = initializer;
		}

		public static <T> ObjectArrayInitializer<T> create(T[] arr, final IObjectInitializer<T> initializer)
		{
			return new ObjectArrayInitializer<T>(arr, initializer);
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = initializer.initialValue(scanner);
		}

		public T[] getArray()
		{
			return this.arr;
		}
	}


	public static class ByteArrayInitializer implements IArrayInitializer {
		protected byte[] arr;

		private ByteArrayInitializer(final int n)
		{
			this.arr = new byte[n];
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = scanner.nextByte();
		}

		public byte[] getArray()
		{
			return this.arr;
		}
	}

	public static class ShortArrayInitializer implements IArrayInitializer {
		protected short[] arr;

		private ShortArrayInitializer(final int n)
		{
			this.arr = new short[n];
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = scanner.nextShort();
		}

		public short[] getArray()
		{
			return this.arr;
		}
	}

	public static class IntArrayInitializer implements IArrayInitializer {
		protected int[] arr;

		private IntArrayInitializer(final int n)
		{
			this.arr = new int[n];
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = scanner.nextInt();
		}

		public int[] getArray()
		{
			return this.arr;
		}
	}

	public static class LongArrayInitializer implements IArrayInitializer {
		protected long[] arr;

		private LongArrayInitializer(final int n)
		{
			this.arr = new long[n];
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = scanner.nextLong();
		}

		public long[] getArray()
		{
			return this.arr;
		}
	}

	public static class FloatArrayInitializer implements IArrayInitializer {
		protected float[] arr;

		private FloatArrayInitializer(final int n)
		{
			this.arr = new float[n];
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = scanner.nextFloat();
		}

		public float[] getArray()
		{
			return this.arr;
		}
	}

	public static class DoubleArrayInitializer implements IArrayInitializer {
		protected double[] arr;

		private DoubleArrayInitializer(final int n)
		{
			this.arr = new double[n];
		}

		public void initialize(final ContestScanner scanner, final int i) throws IOException {
			this.arr[i] = scanner.nextDouble();
		}

		public double[] getArray()
		{
			return this.arr;
		}
	}

	public String nextToken() throws IOException {
		if(line == null || index >= line.length)
		{
			line = reader.readLine().trim().split(" ");
			index = 0;
		}

		return line[index++];
	}

	public String next() throws IOException {
		return nextToken();
	}

	public String readLine() throws IOException {
		line = null;
		index = 0;

		return reader.readLine();
	}

	public byte nextByte() throws IOException, NumberFormatException {
		return Byte.parseByte(nextToken());
	}

	public short nextShort() throws IOException, NumberFormatException {
		return Short.parseShort(nextToken());
	}

	public int nextInt() throws IOException, NumberFormatException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException, NumberFormatException {
		return Long.parseLong(nextToken());
	}

	public float nextFloat() throws IOException, NumberFormatException {
		return Float.parseFloat(nextToken());
	}

	public double nextDouble() throws IOException, NumberFormatException {
		return Double.parseDouble(nextToken());
	}

	public <T> T nextObject(final ICreator<T> creator) throws IOException, NumberFormatException {
		return creator.createFromToken(this);
	}

	public int[] nextIntArray(final int N) throws IOException, NumberFormatException {
		int[] result = new int[N];

		for(int i=0; i < N; i++) result[i] = nextInt();

		return result;
	}

	public long[] nextLongArray(final int N) throws IOException, NumberFormatException {
		long[] result = new long[N];

		for(int i=0; i < N; i++) result[i] = nextLong();

		return result;
	}

	public float[] nexFloatArray(final int N) throws IOException, NumberFormatException {
		float[] result = new float[N];

		for(int i=0; i < N; i++) result[i] = nextFloat();

		return result;
	}

	public double[] nexDoubleArray(final int N) throws IOException, NumberFormatException {
		double[] result = new double[N];

		for(int i=0; i < N; i++) result[i] = nextDouble();

		return result;
	}

	public <T> T[] nextObjectArray(T[] result, final ICreator<T> creator) throws IOException, NumberFormatException {
		for(int i=0, N=result.length; i < N; i++) result[i] = nextObject(creator);

		return result;
	}

	public <T> ArrayList<T> nextGenericObjectArrayList(final int N, final ICreator<T> creator) throws IOException, NumberFormatException {
		ArrayList<T> result = new ArrayList<T>();
		for(int i=0; i < N; i++) result.add(nextObject(creator));

		return result;
	}

	public void nextTable(final int N, IArrayInitializer... arrayInitializers) throws IOException, NumberFormatException {
		for(int i=0; i < N; i++) for(IArrayInitializer initializer: arrayInitializers)
		{
			initializer.initialize(this, i);
		}
	}
}
