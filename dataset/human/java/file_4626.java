import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		int cannotNum = Math.max(c-a-b-1,0);

		// System.out.println(cannotNum);

		System.out.println(b+c - cannotNum);



	}
}
