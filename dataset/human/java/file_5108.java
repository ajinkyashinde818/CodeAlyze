import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		String s = sc.next();
		int q = sc.nextInt();
		StringBuilder sb = new StringBuilder(s);
		StringBuilder head = new StringBuilder();
		StringBuilder tail = new StringBuilder();
		boolean flg = true;
		for(int i = 0; i < q; i++){
		    int type = sc.nextInt();
		    if(type == 1){
		        flg = !flg;
		    }else{
		        int f = sc.nextInt();
		        char c = sc.next().charAt(0);
		        if(f == 1){
		            if(flg){
		                head.append(c);
		            }else{
		                tail.append(c);
		            }
		        }else{
		            if(flg){
		                tail.append(c);
		            }else{
		                head.append(c);
		            }
		        }
		    }
		}
		// 計算
		String result = "";
		head.reverse().append(sb).append(tail);
		if(flg){
		    result = head.toString();
		}else{
		    result = head.reverse().toString();
		}
		
		
		// 出力
		System.out.println(result);
	}
}
