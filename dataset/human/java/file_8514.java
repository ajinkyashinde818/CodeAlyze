import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int counter = 0;
		List<Integer> list = new ArrayList<>();

		for(int i=1;i<=a||i<=b;i++) {
			if(a%i == 0 && b%i == 0) {
				counter++;
				list.add(i);
			}
		}
		System.out.println(list.get(counter - k));
	}

}
