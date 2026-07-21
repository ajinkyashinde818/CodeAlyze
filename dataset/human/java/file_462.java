import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int r = sc.nextInt();
		
		// 計算
		int result = 0;
		if(n >= 10) {
		    result = r;
		}else{
		    result = r + 100*(10-n);
		}
		
		
		// 出力
		System.out.println(result);
	}
}
