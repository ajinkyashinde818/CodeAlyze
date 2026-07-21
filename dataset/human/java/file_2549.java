import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String T = sc.next();
		sc.close();
		char[] ch1 = S.toCharArray();
		char[] ch2 = T.toCharArray();
		List<Character> list1 = new ArrayList<>();
		List<Character> list2 = new ArrayList<>();
		for(int i = 0;i < ch1.length;i++) {
			list1.add(ch1[i]);
		}
		for(int i = 0;i < ch2.length;i++) {
			list2.add(ch2[i]);
		}
		Collections.sort(list1);
		Collections.sort(list2,Comparator.reverseOrder());
		String S2 = "";
		String T2 = "";
		for(int i = 0;i < list1.size();i++) {
			S2 += list1.get(i);
		}
		for(int i = 0;i < list2.size();i++) {
			T2 += list2.get(i);
		}
		if(S2.compareTo(T2) < 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
