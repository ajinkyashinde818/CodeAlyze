import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int n = sc.nextInt();

		int a[] = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
		}

		int b[] = new int[n];
		for(int i = 0; i < n; i++){
			b[i] = sc.nextInt();
		}

		int c[] = new int[n];
		for(int i = 0; i < n-1; i++){
			c[i] = sc.nextInt();
		}
		// System.out.println(Arrays.toString(c));

		int manzoku = 0;
		for(int i = 0; i<n; i++){
			// System.out.println("i="+i);
			if(i != 0 && a[i] == a[i-1]+1){
				manzoku = manzoku + b[a[i]-1] + c[a[i]-2];
				// System.out.println("*b="+b[a[i]-1]);
				// System.out.println("c[a[i]]="+c[a[i]-2]);
			}else{
				manzoku += b[a[i]-1];
				// System.out.println("b="+b[a[i]-1]);
			}
		}

		// 出力
		System.out.println(manzoku);
	}
}
