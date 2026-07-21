import java.util.*;
import java.io.*;
import java.math.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int max = (int)Math.pow(10,9);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        ArrayList<Integer> li = new ArrayList<Integer>();
        for(int i = 0; i < k; i++){
            System.out.print(s+" ");
        }
        for(int i = k; i < n; i++){
            int prt = (s+1) % max;
            System.out.print(prt +" ");
        }
    }
}
