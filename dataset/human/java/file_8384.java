import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int a = sc.nextInt();
		// スペース区切りの整数の入力
		int b = sc.nextInt();
		int c = 0;
		boolean d = true;
		for(long i = 0; d; i++){
			c += a;
			c = c % b;
			if(c == 0){
				System.out.println(a * (i + 1));
				d = false;
			}
		}		
	}
}
