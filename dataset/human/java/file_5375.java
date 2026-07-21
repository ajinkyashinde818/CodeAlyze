import java.util.*;
import java.io.*;
 
public class Main {
    
    static int m;
    static int n;
    static ArrayList<Integer>[] next;
    static boolean[] dp;
    static int[] count;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(br.readLine());
        System.out.println((n<1200) ? "ABC":"ARC");
    }
    
}
