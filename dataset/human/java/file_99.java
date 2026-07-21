import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// 整数の入力
		int n = sc.nextInt();

		int[] B = new int[n];
		int minus = 0;
		boolean flg = true;

		for(int i=0;i<n;i++){
			int a = sc.nextInt();
			if(a<0){
				a = -a;
				minus++;
			} else if(a==0){
				flg = false;
			}
			B[i] = a;
		}

		if(minus%2==1&&flg){
			Arrays.sort(B);
			B[0]=-B[0];
		}

		long sum = 0;

		for(int i=0;i<n;i++){
			sum += B[i];
		}

		// 出力
		System.out.println(sum);
	}
}
