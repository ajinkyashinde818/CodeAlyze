import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int N = sc.nextInt();
		long a[] = new long[N] ;
		long absmin = Long.MAX_VALUE ;
		int minusCount = 0 ;
		for( int i = 0 ; i < N ; i ++) {
			a[i] = sc.nextInt();

			if(a[i] < 0) {
				minusCount ++ ;
			}
			long abs = a[i] ;
			if(abs < 0) {
				abs = (-1)*abs;
			}
			a[i] = abs ;
			if(abs < absmin) {
				absmin = abs ;
			}
		}


		long sum = 0 ;
		for( int i = 0 ; i < N ; i ++) {
			sum += a[i] ;
		}

		if(!(minusCount%2 == 0)) {
			sum = sum - (2*absmin) ;
		}
		// 出力
		System.out.println(sum);

	}

}
