import java.util.Scanner;

public class Main{
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		StringBuilder center = new StringBuilder();
		StringBuilder atama = new StringBuilder();
		StringBuilder ketsu = new StringBuilder();

		center.append(scanner.nextLine());
		int n  = Integer.parseInt(scanner.nextLine());
		int t  = 0;
		int m  = 0;
		int f  = 0;


		for(int i = 0; i < n; i++) {

			m  = scanner.nextInt();
			t += m;

			if(m == 2){

				f  		= scanner.nextInt();
				char c  = scanner.next().toCharArray()[0];

				if(f == 1 && t % 2 == 0) {

					 atama.append(c);

				}else if(f == 2 && t % 2 == 1) {

					 atama.append(c);

				}else {
					 ketsu.append(c);
				}
			}
		}

		if(t % 2 == 0) {

			System.out.println(atama.reverse().toString()+ center.toString() + ketsu.toString());

		}else {
			System.out.println(ketsu.reverse().toString()+ center.reverse().toString() + atama.toString());
		}
	}
}
