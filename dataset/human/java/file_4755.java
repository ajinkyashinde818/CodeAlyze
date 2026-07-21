import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		String s = sc.next();
		
		// 計算
		//int cnt = 0;
		//while(cnt < 101){
		long result = 0;
		//s = String.valueOf(cnt);
		int len = s.length();
		int next = 0;
		int five = 0;
		for(int i = len-1; i >= 0; i--){
		    int n = s.charAt(i) - '0';
		    n += next;
		    if(n >= 5) n += five;
		    if(n <= 4){
		        result += n;
		        next = 0;
		        five = 0;
		    }else if(n == 5){
		        result += n;
		        next = 0;
		        five = 1;
		    }else{
		        result += 10 - n;
		        next = 1;
		        five = 0;
		    }
		}
		result += next;
		
		// 出力
		System.out.println(result);
		//System.out.println(cnt + ":" + result);
		//cnt++;
		//}
	}
}
