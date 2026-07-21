import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long total = 1;
		long A = sc.nextInt();
		long B = sc.nextInt();
		//A>B←条件　?がifの役割 A:B 左がtrue,右がfalse
		long c = A>B? A:B;
		List<Long> list = new ArrayList<Long>();
		boolean bool = true;
		//boolにfalseが入るまで繰り返す。
		while(bool) {

			for(long i = c; i <= c ;i--  ) {
				if(A%i == 0 && B%i ==0) {
					list.add(i);
					A = A / i;
					B = B / i;
					break;
				}
				if(i <= 2) {
					bool = false;
					break;

				}
			}

		}
		list.add(A);
		list.add(B);
		for(int i = 0; i < list.size(); i++) {
			total = total * list.get(i);
		}
		System.out.println(total);
	}

}
