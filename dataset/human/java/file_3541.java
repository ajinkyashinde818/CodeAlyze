import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// 入力
		String x = sc.next();
		String y = sc.next();
		
		// 計算
		String result = "=";

		if(x.compareTo(y) > 0){
		    result = ">";
		}else if(x.compareTo(y) < 0){
		    result = "<";
		}

		// 出力
		System.out.println(result);
	}
}
