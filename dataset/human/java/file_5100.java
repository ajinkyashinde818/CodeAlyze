/*
 *  author : Atul Anand   
 *  created on : Tue Mar 31 2020
 */

import java.io.*;
import java.util.*;

public class Main{

    public static void main(String[] args) throws IOException {
        String S = in.next();
        int Q = in.nextInt();
        LinkedList<Character> L = new LinkedList<>();
        for(char c: S.toCharArray()){
            L.add(c);
        }
        boolean reverse = false;
        while(Q-->0){
            int T = in.nextInt();
            if(T == 1){
                reverse = !reverse;
            }
            else{
                int F = in.nextInt();
                char C = in.next().charAt(0);
                if(reverse){             
                    if(F == 1){
                        // insert at last
                        L.add(C);
                    }
                    else{
                        // insert at beginning
                        L.addFirst(C);
                    }
                }
                else{
                    if(F == 1){
                        // insert at beginning
                        L.addFirst(C);
                    }
                    else{
                        // insert at last
                        L.add(C);
                    }
                }
            }
        }
        
        StringBuilder ans = new StringBuilder();
        for(char c: L){
            ans.append(c);
        }
        if(reverse){
            println(ans.reverse().toString());
        }
        else{
            println(ans.toString());
        }
        
        in.close();
        out.close();
    }

    static int MIN = Integer.MIN_VALUE;
    static int MAX = Integer.MAX_VALUE;
    static Reader in = new Reader();
    static PrintWriter out = new PrintWriter(System.out);

    static void read(int arr[], int N) throws IOException { 
    	for(int i = 0; i < N; i++){ 
    		arr[i] = in.nextInt(); 
    	} 
    }
    
    static void read(long arr[], int N) throws IOException { 
    	for(int i = 0; i < N; i++){ 
    		arr[i] = in.nextLong(); 
    	} 
    }
    
    static void read(String arr[], int N) throws IOException { 
    	for(int i = 0; i < N; i++){ 
    		arr[i] = in.next(); 
    	} 
    }
    
    static void print(Object O) {  
    	out.print(O); 
    }
    
    static void println(Object O) { 
    	out.println(O); 
    }
    
    static void println(int arr[]) { 
    	for(int i = 0; i < arr.length; i++){ 
    		print(arr[i]+" "); 
    	} 
    	println(""); 
    }

    static void println(int arr[][]) { 
    	for(int i = 0; i < arr.length; i++){ 
    		println(arr[i]); 
    	}
    }
    
    static void debug(Object O) { 
    	System.out.println(O); 
    }
}

class Reader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    Reader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    String next() throws IOException {
        while (!tokenizer.hasMoreTokens() ) { 
            tokenizer = new StringTokenizer(reader.readLine()); 
        }
        return tokenizer.nextToken();
    }

    int nextInt() throws IOException { 
        return Integer.parseInt(next()); 
    }
    
    double nextDouble() throws IOException { 
        return Double.parseDouble(next());
    }
    
    long nextLong() throws IOException { 
        return Long.parseLong(next()); 
    }
    
    String nextLine() throws IOException { 
        return reader.readLine(); 
    }
    
    void close() throws IOException { 
        reader.close(); 
    }
}
