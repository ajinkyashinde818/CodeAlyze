//2019/3/12
import java.util.Scanner;
public class Main{

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();

		int B = sc.nextInt();

		int K = sc.nextInt();

		int ans = 0;

		int i = 0;

		if(A<B) {

			for(int j=A;i<K;j--) {

				if(A%j==0 && B%j==0) {

					i++;

					ans = j;
				}
			}
		}else {

			for(int j=B;i<K;j--) {

				if(A%j==0 && B%j==0) {

					i++;

					ans = j;
				}
			}
		}
		System.out.println(ans);
	}

}
