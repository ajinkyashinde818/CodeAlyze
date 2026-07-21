import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt(); in.nextLine();
		char[][] guy = new char[n][n];
		char[][] otherguy = new char[m][m];
		for( int i = 0; i < n; i++ ) {
			String temp = in.nextLine();
			for( int j = 0; j < n; j++ ) {
				guy[i][j] = temp.charAt(j);
			}
		}
		for( int i = 0; i < m; i++ ) {
			String temp = in.nextLine();
			for( int j = 0; j < m; j++ ) {
				otherguy[i][j] = temp.charAt(j);
			}
		}

		String ans = "No";	
		if(n!=m) {
			for( int i = 0; i < n-m; i++ ) {
				if( ans.equals("Yes") ) break;
				for( int j = 0; j < n-m; j++ ) {
					//System.out.printf("%d %d\n",i,j);
					if( guy[i][j] == otherguy[0][0] ) {
						boolean yes = true;
						for( int k = 0; k < m; k++ ) {
							for( int p = 0; p < m; p++ ) {
								if( guy[k+i][p+j] != otherguy[k][p] ) {
									yes = false;
									break;
								}
							}
						}
						if(yes) ans = "Yes";
					}
				}
			}
		} else {
			ans = "Yes";
			for( int i = 0; i < n; i++ ) {
				if( ans.equals("No")) break;
				for( int j = 0; j < n; j++ ) {
					if(guy[i][j] != otherguy[i][j]) {
						ans = "No";
						break;
					}
				}
			}
		}

		System.out.println(ans);
	}

}
