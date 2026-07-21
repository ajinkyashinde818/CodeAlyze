import java.util.*;
    public class Main {
    	public static void main(String[] args){
    		Scanner sc = new Scanner(System.in);
    		// 整数の入力
    		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();

		long ans;

		if (a+b+1 > c){
		    ans = c;
		}else{
		    ans = a+b+1;
		}

		ans += b;

    		// 出力
		System.out.println(ans); 
    	}
    }
