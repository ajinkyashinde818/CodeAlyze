import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		
		char [][]a = new char[n][n];
		char [][]b = new char[m][m];
		
		for(int i = 0 ; i < n ;i++) {
			String s = sc.next();
			for(int j = 0 ; j < n ;j++) {
				a[i][j] = s.charAt(j);
			}
		}
		
		for(int i = 0 ; i < m ;i++) {
			String s = sc.next();
			for(int j = 0 ; j < m ;j++) {
				b[i][j] = s.charAt(j);
			}
		}
		boolean flag = false;
		for(int i = 0 ; i < n-m+1 ;i++) {
			for(int j = 0 ; j < n-m+1 ;j++) {
				if(a[i][j] == b[0][0]) {
					boolean f1 = true;
				f:	for(int y = i ; y < m + i ;y++) {
						for(int x = j ; x < m + j;x++) {
							if(a[y][x] != b[y-i][x-j]) {
								f1 = false;
							}
						}
					}
					if(!flag) {
					flag = f1;
					}
				}
			}
		}
		
		
		if(flag) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		
		

	}

}
