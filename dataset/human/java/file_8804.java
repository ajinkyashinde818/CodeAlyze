import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		sc.close();
		List<Integer> ary = new ArrayList<>();
		int flg = 1;
		while(flg <= A || flg <= B){
			if(A%flg==0&&B%flg==0) {
				ary.add(flg);
			}
			flg++;
		}
		Collections.sort(ary, Collections.reverseOrder());
		System.out.println(ary.get(K-1));
	}
}
