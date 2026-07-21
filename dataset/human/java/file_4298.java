import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// 入力
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
        int[] c = new int[n-1];
		
		for(int i = 0; i < n; i++){
		    a[i] = sc.nextInt();
		}
		for(int i = 0; i < n; i++){
		    b[i] = sc.nextInt();
		}
		for(int i = 0; i < n - 1; i++){
		    c[i] = sc.nextInt();
		}

		// 計算
		int result = 0;
		int pre = -1;

		for(int i = 0; i < n; i++){
		    result = result + b[a[i]-1];
		    if(a[i] == pre + 1) result = result + c[pre - 1];
		    pre = a[i];
		    //System.out.println("pre " + pre + " res " + result);
		}
		
		// 出力
		System.out.println(result);
	}
}
