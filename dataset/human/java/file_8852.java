import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
    
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		// 計算
		int result = 0;
		int c = min(a, b);
		for(int i = c; i > 0; i--){
		    if(a%i == 0 && b%i == 0){
		        k--;
		        result = i;
		        if(k == 0) break;
		    }
		}

		// 出力
		System.out.println(result);
        
	}
}
