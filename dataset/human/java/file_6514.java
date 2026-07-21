import java.io.*;
import java.util.*;

public class Main{
    
    public static void main(String[] args) throws IOException {
        int K = in.nextInt();
        int S = in.nextInt();
        int ans = 0;
        for(int X = 0; X <= K; X++){
            for(int Y = 0; Y <= K; Y++){
                int Z = S - (X+Y);
                if(Z >= 0 && Z <= K){
                    ans++;        
                }
            }
        }
        println(ans);
        in.close();
        out.close();
    }

    static int MIN = Integer.MIN_VALUE;
    static int MAX = Integer.MAX_VALUE;
    static Reader in = new Reader();
    static PrintWriter out = new PrintWriter(System.out);
    static void read(int arr[], int N) throws IOException{ for(int i = 0; i < N; i++){ arr[i] = in.nextInt(); } }
    static void read(long arr[], int N) throws IOException{ for(int i = 0; i < N; i++){ arr[i] = in.nextLong(); } }
    static void read(String arr[], int N) throws IOException{ for(int i = 0; i < N; i++){ arr[i] = in.next(); } }
    static void print(Object O){ out.print(O); }
    static void println(Object O){ out.println(O); }
    static void print(int arr[]){ for(int i = 0; i < arr.length; i++){ print(arr[i]+" "); } println(""); }
    static void print(int arr[][]){ for(int i = 0; i < arr.length; i++){ print(arr[i]); } }
    static void debug(Object O){ System.out.println(O); }
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
