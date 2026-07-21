import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		long n = sc.nextLong();
		
		// 計算
		long result = 0;
		if(n%2 == 1){
		    System.out.println(result);
		    return;
		}
		long k = 10;
		while(k <= n){
		    result += n/k;
		    k *= 5;
		}

		// 出力
		System.out.println(result);
	}
}
