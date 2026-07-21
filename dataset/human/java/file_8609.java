import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		int d = a<b?a:b;

		ArrayList<Integer> foo = new ArrayList<>();

		for(int i=1;i<=d;i++) {

			if(a%i==0 && b%i==0)
				foo.add(i);
		}
		Collections.sort(foo, Collections.reverseOrder());
		System.out.println(foo.get(c-1));
	}
}
