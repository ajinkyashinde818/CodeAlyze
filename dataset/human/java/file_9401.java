import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int n = sc.nextInt();
		
		int cnt =0;
		boolean isWin = false;
		for( int i=0 ; i < n ; i++ ) {
			int d1 = sc.nextInt();
			int d2 = sc.nextInt();
			if( d1 == d2 ) {
				cnt++;
				if( cnt == 3) {
					isWin =true;
				}
			}else {
				cnt =0;
			}
		}
		System.out.println( isWin ? "Yes" :"No");

	}

}
