import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int n = Integer.parseInt(sc.next());
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n - 1];
		for(int i = 0 ; i < n ; i++) a[i] = Integer.parseInt(sc.next());
		for(int i = 0 ; i < n ; i++) b[i] = Integer.parseInt(sc.next());
		for(int i = 0 ; i < n - 1 ; i++) c[i] = Integer.parseInt(sc.next());
		sc.close();
		long yono = 0;
		for(int i = 1 ; i < n ; i++){
			if(a[i - 1] + 1 == a[i]){
				yono += c[a[i - 1] - 1];
			}
		}
		for(int i = 0 ; i < n ; i++) yono += b[a[i] - 1];
		ou.print(yono + "\n");
		ou.flush();
    }
}
