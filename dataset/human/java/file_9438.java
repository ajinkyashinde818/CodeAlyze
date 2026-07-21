import java.util.Scanner;

public class Main {

		public static void main(String[] args) {
			// TODO Auto-generated method stub
			try (Scanner sc = new Scanner(System.in)) {
				int N = sc.nextInt();
				int a = 0;
				int b = 0;
				int count = 0;
				String ans = "No";
				for (int i = 0; i < N; i++) {
					a = sc.nextInt();
					b = sc.nextInt();

					if (count == 0 && a == b) {
						count = 1;
					} else if (count > 0 && a == b) {
						count++;
					} else {
						count = 0;
					}
					if (count > 2) {
						ans = "Yes";
					} 
				}

				System.out.println(ans);
			} catch (Exception e) {
				// TODO: handle exception
			}
		}
}
