import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 整数の入力
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		ArrayList<Integer> aList = new ArrayList<Integer>();
		ArrayList<Integer> bList = new ArrayList<Integer>();
		ArrayList<Integer> ansList = new ArrayList<Integer>();

		for (int i = 1; i <= a; i++) {
			if (a % i == 0) {
				aList.add(i);
			}
		}

		for (int i = 1; i <= b; i++) {
			if (b % i == 0) {
				bList.add(i);
			}
		}

		if(aList.size() > bList.size()){
			for (int val : aList) {
				if(bList.contains(val)){
					ansList.add(val);
				}
			}
		}else{
			for (int val : bList) {
				if(aList.contains(val)){
					ansList.add(val);
				}
			}
		}

		Collections.sort(ansList, Collections.reverseOrder());
		System.out.println(ansList.get(k - 1));

		sc.close();
	}
}
