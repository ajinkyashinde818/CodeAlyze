import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		String s = sc.next();
		
		// 計算
		String result = "No";
		if(s.contains("a") && s.contains("b") && s.contains("c")) result = "Yes";
		
		// 出力
		System.out.println(result);
		
	}

}
