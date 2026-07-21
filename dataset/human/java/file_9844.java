import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {



    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] s = in.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int M = Integer.parseInt(s[1]);
        int X = Integer.parseInt(s[2]);
        List<Integer[]> books = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            s = in.readLine().split(" ");
            Integer[] row = new Integer[s.length];
            for(int j = 0; j < row.length; j++) {
                row[j] = Integer.parseInt(s[j]);
            }
            books.add(row);
        }
        List<Integer[]> curr = new ArrayList<>();
        int ans = recurse(books, 0, curr, Integer.MAX_VALUE, X, M);
        if(ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }

    public static  List<Integer[]> clone( List<Integer[]> list) {
        List<Integer[]> clone = new ArrayList<>();
        for(int i = 0; i < list.size(); i++) {
            Integer[] item = list.get(i);
            Integer[] row = new Integer[item.length];
            for(int j = 0; j < item.length; j++) {
                row[j] = item[j];
            }
            clone.add(row);
        }
        return clone;
    }

    public static void printL(List<Integer[]> curr) {
        for(Integer[] row: curr) {
            System.out.print(row[0] + " ");
        }
        System.out.println();
    }
    public static int recurse(List<Integer[]> books, int start, List<Integer[]> curr, int maxsum, int X, int M) {
        //printL(curr);
        if(curr.size() > 0) {
            int sum = verify(curr, X, M);
            maxsum =  Math.min(maxsum, sum);
        }
        for(int i = start; i < books.size(); i++) {
            List<Integer[]> clone = clone(curr);
            clone.add(books.get(i));
            maxsum = Math.min(recurse(books, i + 1, clone, maxsum, X, M), maxsum);
        }
        return maxsum;
    }

    public static int verify(List<Integer[]> curr, int x, int m) {
        int sum = 0;
        int[] summatrix = new int[m];
        for(int i = 0; i < curr.size(); i++) {
            Integer[] row = curr.get(i);
            for(int j = 0; j < row.length - 1; j++) {
                summatrix[j] += row[j + 1];
            }
            sum += row[0];
        }
        for(int i = 0; i < summatrix.length; i++) {
            if(summatrix[i] < x) return Integer.MAX_VALUE;
        }
        return sum;
    }

}
