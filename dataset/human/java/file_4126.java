import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		ArrayList<Integer> listA = new ArrayList<>();
		ArrayList<Integer> listB = new ArrayList<>();
		ArrayList<Integer> listC = new ArrayList<>();
		for(int i = 0; i < N; i++) {
			listA.add(Integer.parseInt(sc.next()));
		}
		for(int i = 0; i < N; i++) {
			listB.add(Integer.parseInt(sc.next()));
		}
		for(int i = 0; i < N - 1; i++) {
			listC.add(Integer.parseInt(sc.next()));
		}
		sc.close();

		int satisfaction = 0;
		for(int i = 0; i < listA.size(); i++) {
			int tmp = listA.get(i) - 1;
			satisfaction += listB.get(tmp);
			if(i > 0) {
				if(listA.get(i) == listA.get(i - 1) + 1) {
					satisfaction += listC.get(listA.get(i - 1) - 1);
				}else {
					continue;
				}
			}
		}
		System.out.println(satisfaction);

	}
}
