import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		
		// 計算
		String result = "";
		//StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++){
		    if(i < k){
		        System.out.print(s);
		        System.out.print(" ");
		    }else{
		        if(s != 1000000000)System.out.print(s+1);
		        if(s == 1000000000)System.out.print(s-1);
		        System.out.print(" ");
		    }
		}

		// 出力
		System.out.println(result);
	}
}
