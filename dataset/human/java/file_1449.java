import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		char[][] p = new char[n][n];
		char[][] q = new char[m][m];
		String s;
		for(int i = 0 ; i < n ; i++){
			s = sc.next();
			for(int j = 0 ; j < n ; j++) p[i][j] = s.charAt(j);
		}
		for(int i = 0 ; i < m ; i++){
			s = sc.next();
			for(int j = 0 ; j < m ; j++) q[i][j] = s.charAt(j);
		}
		sc.close();
		boolean fin = true;
		for(int i = 0 ; i <= n - m && fin ; i++){
			for(int j = 0 ; j <= n - m && fin ; j++){
				boolean eq = true;
				for(int ii = i ; ii < i + m ; ii++){
					for(int jj = j ; jj < j + m ; jj++){
						if(p[ii][jj] != q[ii - i][jj - j]) eq = false;
					}
				}
				if(eq) fin = false;
			}
		}
		if(fin) ou.println("No");
		else ou.println("Yes");
		ou.flush();
	}
}
