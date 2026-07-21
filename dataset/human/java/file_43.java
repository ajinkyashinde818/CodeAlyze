import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;


public class Main {
    void run() {
        Kattio io = new Kattio(System.in, System.out);
        int[] table = new int[100005];
        for (int i = 0; i < table.length; i++)
            table[i] = -1;
        for (int i = 1; i * (i + 1) <= 200000; i++) {
            if (i * (i + 1) % 2 == 0) {
                table[i*(i+1)/2] = i;
            }
        }
        int n = io.getInt();
        if (table[n] == -1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            int x = n, time = table[n], y = n;
            System.out.println(time+1);
            int[][] res = new int[time+1][time+1];
            int i = 0, j = 1;
            for (int t = 0; t < time; t++) {
                for (int _i = i; _i < time; _i++) {
                        res[t][_i] = x;
                        x--;
                }
                for (int _j = j; _j < time+1; _j++) {
                    res[_j][t] = y;
                    y--;
                }
                i++; j++;

            }
            for (int t = 0; t < time + 1; t++) {
                System.out.printf("%d ", time);
                for (int k = 0; k < time; k++) {
                    System.out.printf("%d ", res[t][k]);
                }
                System.out.println();
            }
        }
    }

    public static void main (String [] args) {
        new Main().run();
    }
}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
		super(new BufferedOutputStream(System.out));
		r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
		super(new BufferedOutputStream(o));
		r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
		return peekToken() != null;
    }

    public int getInt() {
		return Integer.parseInt(nextToken());
    }

    public double getDouble() { 
		return Double.parseDouble(nextToken());
    }

    public long getLong() {
		return Long.parseLong(nextToken());
    }

    public String getWord() {
		return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
	if (token == null) 
	    try {
		      while (st == null || !st.hasMoreTokens()) {
		    	line = r.readLine();
		    	if (line == null) return null;
		    	st = new StringTokenizer(line);
			}
				token = st.nextToken();
	    	} catch (IOException e) { }
		return token;
    }

    private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
    }
}
