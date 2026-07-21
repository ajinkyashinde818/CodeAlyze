import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String S = scanner.next();

		List<String> list1 = new ArrayList<>(3);
		for (int i = 0; i < 3; i++) {
			list1.add(S.substring(i,i+1));
		}
		int l1 = list1.size();

		List<String> list2 = new ArrayList<>(new HashSet<>(list1));
		int l2 = list2.size();

		/*
		for (String s : list1) {
			System.out.println("list1" + s);
		}
		for (String s : list2) {
			System.out.println("list2" + s);
		}
		System.out.println("l1：" +l1 + "l2：" + l2);
		*/
		if (l1 == l2) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
