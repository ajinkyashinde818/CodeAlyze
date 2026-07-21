import java.util.*;
import java.io.*;
import java.util.Arrays; 
import java.util.ArrayList; 
import java.util.Collections; 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        try (PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out))) {
            FastScanner in = new FastScanner(System.in);
            int nRolls = in.nextInt();
            int nDices = nRolls*2;
            int[] dices = in.nextIntArray(nDices);

            boolean check = false;

            for(int i = 0; i < nDices - 4; i = i+2) {
                if(dices[i] == dices [i+1] && dices[i+2] == dices [i+3] && dices[i+4] == dices [i+5]) {
                    check = true;
                    break;
                }
            }
            if(check) {
                out.println("Yes");
            } else {
                out.println("No");
            }



        } finally {
            //out.close();
        }
        
           
    }
}


class FastScanner {
   private final BufferedReader br;
   private StringTokenizer st;
 
    FastScanner(InputStream InputStream) {
        br = new BufferedReader(new InputStreamReader(InputStream));
    }
    
    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
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


    
    ArrayList<Integer> nextIntList(int count) {
        ArrayList<Integer> array = new ArrayList<>();
        for (int n = 0; n < count; n++) {
            int number = nextInt();
            array.add(number);
        }
        return array;
    }
    
    int[] nextIntArray(int count) {
        int[] array = new int[count];
        for (int n = 0; n < count; n++) {
            array[n] = nextInt();
        }
        return array;
    }
}
