import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		List<Integer> list = new ArrayList<Integer>();
		for(int tmp = 1; tmp <= a || tmp <= b; tmp++) {
			if(a % tmp == 0 && b % tmp == 0) {
				list.add(tmp);
			}
		}
		System.out.println(list.get(list.size() - c));
	}
}
