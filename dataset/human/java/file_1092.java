import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] result = new int[n];
		for(int i = 0; i < n; i++){
		    a[i] = sc.nextInt();
		}
		for(int i = 0; i < n; i++){
		    b[i] = sc.nextInt();
		    result[n-i-1] = b[i]; 
		}

		// 計算
		//int result = 0;
		int l  = 0;
		int r = n-1;
		for(int i = 0; i < n; i++){
		    if(a[i] == result[i]){
		        if(a[l] != result[l] && a[l] != result[i] && a[i] != result[l]){
		            int tmp = result[l];
		            result[l] = result[i];
		            result[i] = tmp;
		            l++;
		        }else if(a[r] != result[r] && a[r] != result[r] && a[i] != result[r]){
		            int tmp = result[r];
		            result[r] = result[i];
		            result[i] = tmp;
		            r--;
		        }else{
		            System.out.println("No");
		            return;
		        }
		    }
		    //for(int j = 0; j < n; j++){System.out.print(result[j] + " ");}System.out.println();
		}
		
		// 出力
		//System.out.println(result);
		System.out.println("Yes");
		for(int i = 0; i < n; i++){
		    System.out.print(result[i] + " ");
		}
	}
	
	public static class Scanner {
		private BufferedReader br; private StringTokenizer tok;
		public Scanner(InputStream is) throws IOException { br = new BufferedReader(new InputStreamReader(is));}
		private void getLine() throws IOException { while(!hasNext()) tok = new StringTokenizer(br.readLine());}
		private boolean hasNext() { return tok != null && tok.hasMoreTokens();}
		public String next() throws IOException { getLine(); return tok.nextToken();}
		public int nextInt() throws IOException { return Integer.parseInt(next());}
		public long nextLong() throws IOException { return Long.parseLong(next());}
		public double nextDouble() throws IOException { return Double.parseDouble(next());}
	}

}
