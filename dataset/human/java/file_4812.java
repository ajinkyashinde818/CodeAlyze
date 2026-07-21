import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		long a = sc.nextLong();
		long b = 0;
		if( a % 2 == 1){
			System.out.println(0);
		}else{
			a = a / 10;
			b += a;
			while(a > 4){
				a = a / 5;
				b += a;
			}
			System.out.println(b);
		}
		
		
		
	}
}
