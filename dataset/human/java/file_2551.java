import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        Reader r = new Reader();  
        String s = r.s();
        String t = r.s();
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();
        Arrays.sort(sc);
        Arrays.sort(tc);
        char[] temp = new char[tc.length];
        for(int i = 0; i < tc.length; i++)
            temp[i] = tc[tc.length-1-i];
        tc = temp;
        s = new String(sc);
        t = new String(tc);
        println(s.compareTo(t) < 0 ? "Yes" : "No");
    }
    static class EdgeList{
        int id;
        ArrayList<int[]> list = new ArrayList<>();
        int d;
        EdgeList(int n){
            id = n;
        }
        void add(int[] a){
            list.add(a);
        }
        int size(){
            return list.size();
        }
        void setD(int d){
            this.d = d;
        }
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
    static class Reader extends BufferedReader{
        Reader(){
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
