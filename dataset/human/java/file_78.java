import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int[] a = new int[n];
		long sum = 0;
		for(int i = 0; i < n; i++){
		    a[i] = sc.nextInt();
		    sum += a[i];
		}
		// 計算
		long result = 0;
		Arrays.sort(a);
		//System.out.println(Arrays.toString(a));
		for(int i = 0; i < n - 1; i = i+2){
		    if(a[i] >= 0){
		        break;
		    }else if(a[i+1] <= 0){
		        sum = sum - 2*a[i] - 2*a[i+1];
		    }else{
		        if(a[i] + a[i+1] < 0){
		            sum = sum - 2*a[i] - 2*a[i+1];
		        }
		    }
		}
		result = sum;
		// 出力
        System.out.println(result);
	}
}
