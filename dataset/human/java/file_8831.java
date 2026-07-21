import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		List<Integer> aList = method1(a);
		List<Integer> bList = method1(b);
		
		List<Integer> ansList = new ArrayList<>();
		
		for (Integer d: aList) {
			for(Integer e: bList) {
				if (d.equals(e)) {
					ansList.add(e);
				}
			}
		}
		System.out.println(ansList.get(ansList.size()-k));
	}
	
	public static List<Integer> method1(int a) {
		List<Integer> list = new ArrayList<>();
		for(int i=1; i<=a; i++) {
			if (a%i==0) {
				list.add(Integer.valueOf(i));
			}
		}
		return list;
	}
}
