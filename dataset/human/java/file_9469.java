import java.io.*;
import java.util.*;


public class Main{
	
	public static void main(String[] args){
	
	MyScanner sc = new MyScanner();
	out = new PrintWriter(new BufferedOutputStream(System.out));
	
	/**/
	
	int numberOfRolls = sc.nextInt();
	
	int[][] array = new int[numberOfRolls][2];
	
	for(int i = 0; i < numberOfRolls; i++){
		
		array[i][0] = sc.nextInt();
		array[i][1] = sc.nextInt();
		
	}
	
	for(int i = 0; i <= array.length - 3; i++){
		
		if(array[i][0] == array[i][1] && array[i+1][0] == array[i+1][1] && array[i+2][0] == array[i+2][1]){
			System.out.println("Yes");
			return;
		}
	
		
		
	}
	
	System.out.println("No");
	
	/**/
	 
	 out.close();	
	}
	
	public static PrintWriter out;
	
	public static class MyScanner{
		
		BufferedReader br;
		StringTokenizer st;
		
		public MyScanner(){
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
	
}
