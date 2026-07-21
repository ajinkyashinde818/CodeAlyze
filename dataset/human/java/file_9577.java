import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
    public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int n = Integer.parseInt(sc.next());
		boolean[] a = new boolean[n];
		Arrays.fill(a , false);
		for(int i = 0 ; i < n ; i++){
			int aa = Integer.parseInt(sc.next());
			int bb = Integer.parseInt(sc.next());
			if(aa == bb) a[i] = true;
		}
		boolean q = false;
		for(int i = 0 ; i < n - 2 ; i++){
			if(a[i] && a[i + 1] && a[i + 2]) q = true;
		}
		if(q) ou.println("Yes");
		else ou.println("No");
		ou.flush();
	}
}
