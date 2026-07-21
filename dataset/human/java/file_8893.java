import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		
		List<Integer> list = new ArrayList<>();
		for (int i = 1; i <= Math.min(A, B); i++) {
			if (A % i == 0 && B % i == 0) {
				list.add(i);
			}
		}
		
		list = list.stream().sorted().collect(Collectors.toList());
		
		System.out.println(list.get(list.size()-K));
		
		
	}
}
