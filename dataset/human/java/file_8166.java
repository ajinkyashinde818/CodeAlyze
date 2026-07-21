import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		long a = sc.nextLong();
		long b = sc.nextLong();
		
		// 計算
		long result = lcm(a, b);
		
		
		// 出力
		System.out.println(result);
	}
	static long gcd(long x, long y){
	    if(y == 0) return x;
	    return gcd(y , x%y);
	}
	static long lcm(long x, long y){
	    return x*y/gcd(x, y);
	}
}
