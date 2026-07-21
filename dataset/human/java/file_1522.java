import java.io.*;
import java.util.*;
import static java.lang.System.out;

public class Main{
    static MyReader in = new MyReader();

    public static void main(String[] args){
        int N, M; {int[] a = in.ii(); N = a[0]; M = a[1];}
        String[] A = new String[N];
        for (int i = 0; i < A.length; i++) {
            A[i] = in.s();
        }
        String[] B = new String[M];
        for (int i = 0; i < B.length; i++) {
            B[i] = in.s();
        }
        int L = N - M + 1;
        String ans = "No";
        loop1: for (int i = 0; i < L; i++) {
            loop2: for (int j = 0; j < L; j++) {
                for (int k = 0; k < B.length; k++) {
                    for (int l = 0; l < B.length; l++) {
                        if (A[i + k].charAt(j + l) != B[k].charAt(l)) {
                            continue loop2;
                        }
                    }
                }
                ans = "Yes";
                break loop1;
            }
        }
        out.println(ans);
    }

    static class MyReader extends BufferedReader{
        MyReader(){
            super(new InputStreamReader(System.in));
        }

        String s(){
            try{return readLine();}catch(IOException e){return "";}
        }

        String[] ss(){
            return s().split(" ");
        }

        int i(){
            return Integer.parseInt(s());
        }

        int[] ii(){
            String[] ss = ss();
            int[] ii = new int[ss.length];
            for(int j = 0; j < ss.length; j++) ii[j] = Integer.parseInt(ss[j]);
            return ii;
        }

        ArrayList<Integer> li(){
            String[] ss = ss();
            ArrayList<Integer> li = new ArrayList<>();
            for(int j = 0; j < ss.length; j++) li.add(Integer.parseInt(ss[j]));
            return li;
        }

        long l(){
            return Long.parseLong(s());
        }

        long[] ll(){
            String[] ss = ss();
            long[] ll = new long[ss.length];
            for(int j = 0; j < ss.length; j++) ll[j] = Long.parseLong(ss[j]);
            return ll;
        }
    }
}
