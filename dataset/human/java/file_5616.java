import java.io.*;
import java.util.*;
public class Main {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        int palceHolder = s == 1000000000 ? 1 : s + 1;
        
        for(int i = 0; i < n; i++) {
        	if(i != n-1) {
        		if(i < k) System.out.print(s + " ");
        		else System.out.print(palceHolder + " ");
        	} else {
        		if(i < k) System.out.println(s);
        		else System.out.println(palceHolder);
        	}
        }
    }
}
