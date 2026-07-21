import javax.management.MBeanRegistration;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.sql.SQLSyntaxErrorException;
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


        long n = Reader.nextLong();
        long ori = n;

        ArrayList<Integer> lis = new ArrayList<Integer>();
        while (n%2==0)
        {
            lis.add(2);
            n /= 2;
        }

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {

            while (n%i == 0)
            {
                lis.add(i);
                n /= i;
            }
        }

        if (n > 2){
            lis.add((int)n);
        }

        long size =1;

        long prev =0;
        long curr =-1;
        long ans=0;

        long same_count =0;
        for (int i=0; i<lis.size(); i++){
            curr=lis.get(i);

            if (curr==prev){
                same_count++;
                if (same_count==size){
                    size++;
                    same_count=0;
                    ans++;
                }
            }
            else {
                ans++;
                size=2;
                same_count=0;
            }
            prev=curr;
        }

        if (ori==1){
            System.out.println(0);
        }
        else {
            System.out.println(ans);
        }





    }

}

class Node_compare implements Comparator<Node>
{
    // Used for sorting in ascending order of
    // roll number
    public int compare(Node n1, Node n2)
    {
        if (n1.a.length()>n2.a.length()){
            return 1;
        }
        else if (n1.a.length()==n2.a.length()) {
            return n2.ind-n1.ind;
        }
        else {
            return -1;
        }

    }
}

class Node{
    String a;
    int ind;


}



class solu{

    int bin (int[][] arr, int l, int r, int val){
        while(r-l>1){
            int m = l+((r-l)/2);
            if (arr[m][0]>=val){
                r=m;
            }
            else {
                l=m;
            }
        }
        return r;
    }

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
