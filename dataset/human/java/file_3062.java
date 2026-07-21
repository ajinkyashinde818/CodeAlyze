import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        MyReader r = new MyReader();    
        int N, M;
        {int[] a = r.ii(); N = a[0]; M = a[1];}
        boolean[] x = new boolean[N];
        boolean[] y = new boolean[N];
        for(int i = 0; i < M; i++){
            int[] z = r.ii();
            if(z[0] == 1)
                x[z[1]-1] = true;
            else if(z[1] == N)
                y[z[0]-1] = true;
        }
        for(int i = 0; i < N; i++){
            if(x[i]&&y[i]){
                println("POSSIBLE");
                return;
            }
        }
        println("IMPOSSIBLE");
    }
    static void print(Object o){
        System.out.print(o.toString());
    }
    static void println(Object o){
        System.out.println(o.toString());
    }
    static int Int(String s){
        return Integer.parseInt(s);
    }
    static long Long(String s){
        return Long.parseLong(s);
    }
    static class MyReader extends BufferedReader{
        MyReader(){
            super(new InputStreamReader(System.in));
        }
        String s() throws IOException{
            return readLine();
        }
        String[] ss() throws IOException{
            return s().split(" ");
        }
        int i() throws IOException{
            return Int(s());
        }
        int[] ii() throws IOException{
            String[] ss = ss();
            int size = ss.length;
            int[] ii = new int[size];
            for(int j = 0; j < size; j++) ii[j] = Int(ss[j]);
            return ii;
        }
        long l() throws IOException{
            return Long(s());
        }
        long[] ll() throws IOException{
            String[] ss = ss();
            int size = ss.length;
            long[] ll = new long[size];
            for(int j = 0; j < size; j++) ll[j] = Long(ss[j]);            
            return ll;
        }
    }
}
