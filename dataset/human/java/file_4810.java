import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		sc.close();
		
		if(N%2==1) {
			System.out.println(0);
			return;
		}
		
		//nの二重階乗を２で割ると、階乗になる。
		long M = N/2; //このとき、２でn回わってることに注意。２の数に追加する必要がある。
		//2の数（求める必要はないが、勉強のため）
		long num2 = N;
		while(M>0) {
			M /= 2;
			num2 += M; 
		}
		//5の数
		M = N/2;
		long num5 = 0;
		while(M>0) {
			M /= 5; // 5の次は25を調べるが、これはMを５で割っても同じことが調べられる。
			num5 += M;
		}
		long ans = Math.min(num2, num5);
		System.out.println(ans);
	}
}
