import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int z = 0;
		ArrayList<Integer> d1 = new ArrayList<>();
		ArrayList<Integer> d2 = new ArrayList<>();

		for(int i=0;i<n;i++) {

			d1.add(sc.nextInt());
			d2.add(sc.nextInt());

		}
		for(int i=0;i<n;i++) {

			if(d1.get(i)==d2.get(i)) {
				z++;
			}else {
				z=0;
			}

			if(z==3) {
				break;
			}

		}

		if(z==3) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}


	}

}
