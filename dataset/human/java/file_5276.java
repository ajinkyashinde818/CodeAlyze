import java.io.*;
import java.util.*;


// 2011/10/22

//0092 ÅåÌ³û`ðT·
public class Main {

	
	// C return falseÅ¨µÜ¢
	boolean main() throws IOException {

		int[] ir = readIntArray();
		int size = ir[0];
		if (size == 0)
			return false;

		int[][] map = new int[size][size];
		
		for(int y = 0; y < size; y++) {
			String s = reader.readLine();
			for(int x = 0; x < size; x++) {
				map[x][y] = s.charAt(x) == '*' ? 1 : 0;
			}
		}
		
		int sq;
		for(sq = 1; sq <= size; sq++) {
			boolean isOK = false;
			loop2:
			for(int x = 0; x < size - sq + 1; x++) {
				for(int y = 0; y < size - sq + 1; y++) {
					
					boolean dame = false;
					loop:
					for(int xx = 0; xx < sq; xx++) {
						for(int yy = 0; yy < sq; yy++) {
							if (map[x + xx][y + yy] != 0) {
								dame = true;
								break loop;
							}
						}
					}
					if (!dame) {
						isOK = true;
						break loop2;
					}
				}
			}
			if (!isOK) {
				break;
			}
		}
		int max = sq-1;
		
		
		// ðÌ\¦
		System.out.printf("%d\n", max);
		
		return true; // ³íI¹ Ö
	}
	

//	private final static boolean DEBUG = true;  // debug
	private final static boolean DEBUG = false; // release

	public static void main(String[] args) throws IOException {

		if (DEBUG) {
			log = System.out;
			
			String inputStr = "10,...*....**,..........,**....**..,........*.,..*.......,..........,.*........,..........,....*..***,.*....*...,0,";

			inputStr = inputStr.replace(",", "\n");

			reader = new BufferedReader(new StringReader(inputStr)); 

		}
		else {
			log = new PrintStream(new OutputStream() { public void write(int b) {} } ); // «ÌÄ
			reader = new BufferedReader(new InputStreamReader(System.in)); // R\[©ç
		}
		
		//int N = readIntArray()[0];

		for(int i = 0; /*i < N*/; i++) {
			boolean b = new Main().main();
			if (!b)
				break;
		}		
		
		reader.close();
	}

	
	static PrintStream log;
	static BufferedReader reader;
	

	// WüÍæè1sªÌXy[XæØèÌ®lðÇÞ
	// EOFÌêÍnullðÔ·
	private static int[] readIntArray() throws IOException {
		
		String s = reader.readLine();
		if (s == null)
			return null;
		String[] sp = s.split(" ");
		int[] a = new int[sp.length];
		for(int i = 0; i < sp.length; i++) {
			a[i] = Integer.parseInt(sp[i]);
		}
		return a;
	}
		
}
