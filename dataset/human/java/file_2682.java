import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		LinkedList<String> sList = new LinkedList<>();
		LinkedList<String> tList = new LinkedList<>();
		String s = "";
		String t = "";

		String input1 = scan.next();
		int len1 = input1.length();
		String input2 = scan.next();
		int len2 = input2.length();


		for(int i = 0; i < len1; i++){
			String temp = input1.substring(0, 1);
			sList.add(temp);
			if(i < len1 - 1) {
				input1 = input1.substring(1);
			}
		}
		for(int i = 0; i < len2; i++){
			String temp = input2.substring(0, 1);
			tList.add(temp);
			if(i < len2 - 1) {
				input2 = input2.substring(1);
			}
		}

		Collections.sort(sList);
		Collections.sort(tList, Comparator.reverseOrder());

		while(sList.size() > 0){
			s = s.concat(sList.poll());
		}
		while(tList.size() > 0){
			t = t.concat(tList.poll());
		}

		if(s.compareTo(t) < 0){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}





	}
}
