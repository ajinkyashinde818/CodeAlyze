// created on : Sun May 31 2020
 
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        long n = in.nextLong();
        List<Long> factors = primeFactors(n);
        HashMap<Long, Integer> map = new HashMap<>();
        for(Long f: factors){
            map.put(f, map.getOrDefault(f, 0) + 1);
        }
        // for each factor, we could divide by power of 1, 2, 3,...
        int ans = 0;
        for(Long f: map.keySet()){
            int val = map.get(f);
            int count = 1;
            while(val >= count){
                val -= count;
                count++;
                ans++;
            }
        }
        println(ans);
        in.close();
        out.close();
    }

    public static ArrayList<Long> primeFactors(long n){
        ArrayList<Long> A = new ArrayList<>();
        while(n % 2 == 0){
            n = n/2;
            A.add(2L);
        }
        for(long i = 3; i*i <= n; i += 2){
            while(n % i == 0){
                n = n/i;
                A.add(i);
            }
        }
        if(n > 1){
            A.add(n);
        }
        return A;
    }

    static int MIN = Integer.MIN_VALUE;
    static int MAX = Integer.MAX_VALUE;
    static Reader in = new Reader();
    static PrintWriter out = new PrintWriter(System.out);

    static int[] readInt(int N) throws IOException { 
    	int arr[] = new int[N];
    	for(int i = 0; i < N; i++){ 
    		arr[i] = in.nextInt(); 
    	} 
    	return arr;
    }
    
    static long[] readLong(int N) throws IOException { 
    	long arr[] = new long[N];
    	for(int i = 0; i < N; i++){ 
    		arr[i] = in.nextLong(); 
    	} 
    	return arr;
    }
    
    static String[] readString(int N) throws IOException { 
    	String arr[] = new String[N];
    	for(int i = 0; i < N; i++){ 
    		arr[i] = in.next(); 
    	} 
    	return arr;
    }
    
    static void print(Object O) {  
    	out.print(O); 
    }
    
    static void println(Object O) { 
    	out.println(O); 
    }
    
    static void println(int arr[]) { 
    	for(int i = 0; i < arr.length; i++){ 
    		print(arr[i] + " "); 
    	} 
    	println(""); 
    }
    
    static void debug(Object ... O) { 
    	for(Object obj: O){
    		System.out.print(obj + " ");
    	}
    	System.out.println();
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
