import java.lang.*;
    import java.io.*;
    import java.util.*;
     
     
    public class Main {
    	
    	public static void main(String[] args) throws java.lang.Exception {
    		InputStream inputStream = System.in;
    		OutputStream outputStream = System.out;
    		InputReader in = new InputReader(inputStream);
    		PrintWriter out = new PrintWriter(outputStream);
    		TaskA solver = new TaskA();
    		solver.solve(in, out);
    		out.close();
    	}
    }
     
    class TaskA {
    	
    	public void solve(InputReader in, PrintWriter out) {
    		final String dream = "dream";
    		final String dreamer = "dreamer";
    		final String erase = "erase";
    		final String eraser = "eraser";
    		final int dreamLen = dream.length();
    		final int dreamerLen = dreamer.length();
    		final int eraseLen = erase.length();
    		final int eraserLen = eraser.length();
    		
    		final String s = in.next();
    		final int slen = s.length();
    		int i = 0, j;
    		char ch;
    		
    		while (i < slen) {
    			ch = s.charAt(i);
    			if (ch!='d' && ch!='e') {
    				out.println("NO");
    				return;
    			}
    			
    			boolean flag = false;
    			
    			if (ch == 'e') {
    				if (i+eraserLen <= slen) {
    					if (eraser.equals(s.substring(i, i+eraserLen))) {
    						flag = true;
    						i += eraserLen;
    					}
    				}
    				if (!flag && i+eraseLen <= slen) {
    					if (erase.equals(s.substring(i, i+eraseLen))) {
    						flag = true;
    						i += eraseLen;
    					}
    				}
    			} else {
    				if (i+dreamerLen<=slen && dreamer.equals(s.substring(i, i+dreamerLen))) {
    					flag = true;
    					if (i+dreamLen+eraseLen<=slen && erase.equals(s.substring(i+dreamLen, i+dreamLen+eraseLen))) {
    						i += dreamLen;
    					} else {
    						i += dreamerLen;
    					}
    				} else if (i+dreamLen<=slen && dream.equals(s.substring(i, i+dreamLen))) {
    					flag = true;
    					i += dreamLen;
    				}
    			}
    			
    			if (!flag) {
    				out.println("NO");
    				return ;
    			}
    		}
    		
    		if (i == slen)
    			out.println("YES");
    		else
    			out.println("NO");
    	}
    }
     
    class InputReader {
    	public BufferedReader reader;
    	public StringTokenizer tokenizer;
    	
    	public InputReader(InputStream stream) {
    		reader = new BufferedReader(new InputStreamReader(stream), 32768);
    		tokenizer = null;
    	}
    	
    	public String next() {
    		while (tokenizer==null || !tokenizer.hasMoreTokens()) {
    			try {
    				tokenizer = new StringTokenizer(reader.readLine());
    			} catch (IOException e) {
    				throw new RuntimeException(e);
    			}
    		}
    		return tokenizer.nextToken();
    	}
    	
    	public int nextInt() {
    		return Integer.parseInt(next());
    	}
    	
    	public double nextDouble() {
    		return Double.parseDouble(next());
    	}
    	
    	public long nextLong() {
    		return Long.parseLong(next());
    	}
    }
