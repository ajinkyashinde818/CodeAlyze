import java.io.*;
import java.util.*;
import static java.lang.System.out;

public class Main{
    static MyReader in = new MyReader();

    public static void main(String[] args){
        int[][] d = {{0, 0, 0, 0, 0, 0},
                    {2, 0, 9, 0, 0, 0},
                    {0, 3, 0, 0, 0, 0},
                    {0, 0, 4, 0, 0, 0},
                    {0, 0, 0, 5, 0, 0},
                    {0, 0, 0, 0, 6, 0},
                    {2, 0, 7, 0, 0, 0},
                    {0, 8, 0, 0, 0, 0},
                    {2, 0, 9, 11, 0, 0},
                    {0, 10, 0, 0, 0, 0},
                    {0, 0, 0, 11, 0, 0},
                    {0, 0, 0, 0, 0, 12},
                    {0, 0, 13, 0, 0, 0},
                    {2, 1, 9, 0, 0, 0}};
        int s = 1;
        String S = in.s();
        final int N = S.length();

        for(int i = 0; i < N; i++){
            char c = S.charAt(i);
            int x = c == 'd' ? 0 :
                    c == 'r' ? 1 :
                    c == 'e' ? 2 :
                    c == 'a' ? 3 :
                    c == 'm' ? 4 :
                    c == 's' ? 5 : 6;
            if(x == 6 || (s = d[s][x]) == 0) {
                out.println("NO");
                return;
            }
        }

        out.println((s-1)*(s-6)*(s-8)*(s-13) == 0 ? "YES" : "NO");
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
