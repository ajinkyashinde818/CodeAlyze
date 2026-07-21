import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.lang.Integer;
import java.util.HashMap;

public class Main {
    // driver function to test the above functions
    public static void main(String args[]) throws IOException {
        Reader.init(System.in);

        int k = Reader.nextInt();
        int n = Reader.nextInt();
        ArrayList<Integer> lis = new ArrayList<Integer>();
        for (int i=0; i<n; i++){
            int val = Reader.nextInt();
            lis.add(val);
            if (val!=0){
                lis.add(val-k);
            }

        }

        Collections.sort(lis);
        int ans=0;
        int prev = lis.get(0);
        int curr = 0;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for (int i=1; i<lis.size(); i++){
            curr = lis.get(i);
            arr.add(Math.abs(curr-prev));
            prev = curr;
        }
        int ans_min=Integer.MAX_VALUE;
        for (int i=0; i<arr.size(); i++){
            if (i<n-1){
                ans=ans+arr.get(i);
            }
            else {
                int temp_1 = ans - (arr.get(i-(n-1))) + arr.get(i);
                if (temp_1<ans_min){
                    ans_min=temp_1;
                }
                ans=temp_1;
            }
        }

        System.out.println(ans_min);


    }
}

class Node{
    char val;
    Node nxt = null;
    Node prev=null;


}



class solu{

}

/** Class for buffered reading int and double values */
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static long nextLong() throws IOException {
        return Long.parseLong( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    static String line() throws IOException {
        return reader.readLine();
    }
}
