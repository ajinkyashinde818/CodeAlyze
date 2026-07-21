import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.time.LocalTime;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


public class Main {

    public static void main(String[] args) {
    
    	FastScanner scan = new FastScanner();
    	
    	int n = scan.nextInt();
    	int [][] arr = new int [n][2];
    	
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<2; j++) {
    			arr[i][j] = scan.nextInt();
    		}
    	}
    	
    	boolean works = false;
    	int count = 0;
    	
    	for(int i=0; i<n; i++) {
    			if(arr[i][0] == arr[i][1]) count++;
    			else count = 0;
    			if(count == 3) works = true;
    	}
    	
    	System.out.println((works) ? "Yes" : "No");
    	
    	
    }

    static class FastScanner{
    	
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer("");
    	String next() {
    		while(!st.hasMoreTokens())
    			try {
    				st = new StringTokenizer(br.readLine());
    			} catch (IOException e){
    				e.printStackTrace();
    			}
    		return st.nextToken();
    	}
    	
    	int nextInt() {
    		return Integer.parseInt(next());
    	}
    	
    	int [] readArray(int n) {
    		int [] a = new int[n];
    		for(int i=0; i<n ; i++) a[i] = nextInt();
    		return a;
    	}
    	
    	long nextLong() {
    		return Long.parseLong(next());
    	}
    	
    	
    }
    
   
}
