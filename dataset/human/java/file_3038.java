import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		int[][] a = new int[2][m];
		for(int j = 0 ; j < m ; j++){
			for(int i = 0 ; i < 2 ; i++) a[i][j] = Integer.parseInt(sc.next()) - 1;
		}
		sc.close();
		boolean[] q = new boolean[n];
		boolean[] p = new boolean[n];
		Arrays.fill(q , false);
		Arrays.fill(p , false);
		for(int i = 0 ; i < m ; i++){
			if(a[0][i] == 0) q[a[1][i]] = true;
			if(a[1][i] == 0) q[a[0][i]] = true;
			if(a[0][i] == n - 1) p[a[1][i]] = true;
			if(a[1][i] == n - 1) p[a[0][i]] = true;
		}
		boolean che = false;
		for(int i = 0 ; !che && i < n ; i++) if(p[i] && q[i]) che = true;
		if(che) ou.println("POSSIBLE");
		else ou.println("IMPOSSIBLE");
		ou.flush();
	}
}
