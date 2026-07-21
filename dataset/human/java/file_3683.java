import java.io.*;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.List;

public class Main {
	private static Object unexpected = null;
	private static final int mod = (int) 1E9 + 7;
	private static final int ibufsize = (1 << 15), obufsize = (1 << 14);
	private static int iNextByte, iNextIndex, iReadByteCount, oNextIndex;
	private static final byte ibuf[] = new byte[ibufsize], obuf[] = new byte[obufsize];
	private static InputStream is = System.in;
	private static OutputStream os = System.out;
	private static Formatter formatter = new Formatter();

	private Main() throws Exception {
		if (inFromFile) is = new FileInputStream(new File("").getAbsolutePath() + "/src/testdata/in.txt");
		if (outToFile) os = new FileOutputStream(new File("").getAbsolutePath() + "/src/testdata/out.txt");
		nextByte();
		solve();
		is.close();
		flushOutBuf();
	}

	public static void main(String[] args) {
		try {
			new Main();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private boolean isDigit(int cp) {
		return '0' <= cp && cp <= '9';
	}

	private boolean isLowercase(int cp) {
		return 'a' <= cp && cp <= 'z';
	}

	private boolean isUppercase(int cp) {
		return 'A' <= cp && cp <= 'Z';
	}

	private boolean isAlphabet(int cp) {
		return ('a' <= cp && cp <= 'z') || ('A' <= cp && cp <= 'Z');
	}

	private boolean isAlphanumberic(char ch) {
		return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' || ch <= 'Z');
	}

	private boolean isWhitespace(int cp) {
		return cp == ' ' || cp == '\r' || cp == '\n' || cp == '\t';
	}

	private boolean isWordSeparator(int cp) {
		return cp == ' ' || cp == '\r' || cp == '\n' || cp == '\t';
	}

	private boolean isLineSeparator(int cp) {
		return cp == '\n' || cp == '\r';
	}

	private boolean isUnexpected() {
		return unexpected != null;
	}

	private Object setUnexpected(Object value) {
		return (unexpected = value);
	}

	private boolean isNegative() throws IOException {
		boolean minus = false;
		while (iNextByte == '+' || iNextByte == '-') {
			if (iNextByte == '-') minus = !minus;
			nextByte();
		}
		return minus;
	}

	private int nextByte() throws IOException {
		if (iNextIndex >= iReadByteCount) {
			iReadByteCount = is.read(ibuf, 0, ibufsize);
			if (iReadByteCount == -1) return (iNextByte = -1);
			iNextIndex = 0;
		}
		return (iNextByte = ibuf[iNextIndex++]);
	}

	private char nc() throws IOException {
		while (iNextByte == ' ' || iNextByte == '\n' || iNextByte == '\t' || iNextByte == '\r') nextByte();
		char res = (char) iNextByte;
		nextByte();
		return res;
	}

	private char[] nc(int n) throws IOException {
		char a[] = new char[n];
		for (int i = 0; i < n; ++i) a[i] = nc();
		return a;
	}

	private char[][] nc(int r, int c) throws IOException {
		char a[][] = new char[r][c];
		for (int i = 0; i < r; ++i) a[i] = nc(c);
		return a;
	}

	private int ni() throws IOException {
		while (isWhitespace(iNextByte)) nextByte();
		int res = 0;
		boolean minus = isNegative();
		if (!isDigit(iNextByte)) return (int) setUnexpected(-1);
		do {res = (res << 1) + (res << 3) + iNextByte - '0';} while (isDigit(nextByte()));
		return minus ? -res : res;
	}

	private int[] ni(int n) throws IOException {
		int a[] = new int[n];
		for (int i = 0; i < n; ++i) a[i] = ni();
		return a;
	}

	private int[][] ni(int r, int c) throws IOException {
		int a[][] = new int[r][c];
		for (int i = 0; i < r; ++i) a[i] = ni(c);
		return a;
	}

	private long nl() throws IOException {
		while (isWhitespace(iNextByte)) nextByte();
		long res = 0;
		boolean minus = isNegative();
		if (!isDigit(iNextByte)) return (long) setUnexpected(-1);
		do {res = (res << 1) + (res << 3) + iNextByte - '0';} while (isDigit(nextByte()));
		return minus ? -res : res;
	}

	private long[] nl(int n) throws IOException {
		long a[] = new long[n];
		for (int i = 0; i < n; ++i) a[i] = nl();
		return a;
	}

	private long[][] nl(int r, int c) throws IOException {
		long a[][] = new long[r][c];
		for (int i = 0; i < r; ++i) a[i] = nl(c);
		return a;
	}

	private double nd() throws IOException {
		while (isWhitespace(iNextByte)) nextByte();
		boolean minus = isNegative();
		if (!isDigit(iNextByte)) return (double) setUnexpected(-1.0);
		double decimal = 0, floating = 0, div = 1;
		do {decimal = 10 * decimal + (iNextByte - '0');} while (isDigit(nextByte()));
		if (iNextByte == '.') while (isDigit(nextByte())) floating += (iNextByte - '0') / (div *= 10);
		double res = decimal + floating;
		return minus ? -res : res;
	}

	private double[] nd(int n) throws IOException {
		double a[] = new double[n];
		for (int i = 0; i < n; ++i) a[i] = nd();
		return a;
	}

	private double[][] nd(int r, int c) throws IOException {
		double a[][] = new double[r][c];
		for (int i = 0; i < r; ++i) a[i] = nd(c);
		return a;
	}

	private String line() throws IOException {
		while (isWhitespace(iNextByte)) nextByte();
		StringBuilder sb = new StringBuilder();
		while (iNextByte != -1 && !isLineSeparator(iNextByte)) {
			sb.append((char) iNextByte);
			nextByte();
		}
		return sb.toString();
	}

	private String ns() throws IOException {
		while (isWordSeparator(iNextByte)) nextByte();
		StringBuilder sb = new StringBuilder();
		while (iNextByte != -1 && !isWordSeparator(iNextByte)) {
			sb.append((char) iNextByte);
			nextByte();
		}
		return sb.toString();
	}

	private String[] ns(int n) throws IOException {
		String a[] = new String[n];
		for (int i = 0; i < n; ++i) a[i] = ns();
		return a;
	}

	private String[][] ns(int r, int c) throws IOException {
		String a[][] = new String[r][c];
		for (int i = 0; i < r; ++i) a[i] = ns(c);
		return a;
	}

	private void flushOutBuf() {
		if (oNextIndex == 0) return;
		try {
			os.write(obuf, 0, oNextIndex);
			os.flush();
			oNextIndex = 0;
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void print(String format, Object... args) {
		if (args != null) format = formatter.format(format, args).toString();
		for (int i = 0, n = format.length(); i < n; ++i) {
			obuf[oNextIndex++] = (byte) format.charAt(i);
			if (oNextIndex >= obufsize) flushOutBuf();
		}
	}

	private <T> void print(T ob) {
		String s = ob + "";
		for (int i = 0, n = s.length(); i < n; ++i) {
			obuf[oNextIndex++] = (byte) s.charAt(i);
			if (oNextIndex >= obufsize) flushOutBuf();
		}
	}

	private <T> void println(T ob) {
		print(ob + "\n");
	}

	private void println(String format, Object... args) {
		print(format + "\n", args);
	}

	private <T> void debug(T ob) {
		print("\u001B[31m" + ob + "\u001B[0m");
	}

	private <T> void debug(String format, Object... args) {
		print("\u001B[31m" + format + "\u001B[0m", args);
	}

	private <T> void debugln(T ob) {
		print("\u001B[31m" + ob + "\u001B[0m\n");
	}

	private void debugln(String format, Object... args) {
		print("\u001B[31m" + format + "\u001B[0m\n", args);
	}

	private void solve() throws Exception {
		char a = nc(), b = nc();
		println(a < b? "<" : a == b? "=": ">");
	}

	private static final boolean inFromFile = false, outToFile = false;
}
