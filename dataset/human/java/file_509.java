import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
//		String s = sc.next();
		int n = sc.nextInt();
		int r = sc.nextInt();

		List<Integer> numList = new ArrayList<>();
		List<Long> ansList = new ArrayList<>();

		if(n >= 10) {
			System.out.println(r);
		}else {
			System.out.println(r+100*(10-n));
		}


	}
}
