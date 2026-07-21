import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		ArrayList<Integer> ans = new ArrayList<>();
		for(int i=1 ; i <= 100 ; i++) {
			if(a%i == 0 && b%i ==0) {
				ans.add(i);
			}
		}
		System.out.println(ans.get(ans.size()-k));
	}
}
