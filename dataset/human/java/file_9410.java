import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int[] array1 = new int[n];
		int[] array2 = new int[n];
		for(int i=0;i<n;i++) {
			array1[i] = sc.nextInt();
			array2[i] = sc.nextInt();
		}
		sc.close();

		boolean flag = false;
		int ans = 0;
		for(int i=0;i<n;i++) {
			int d1 = array1[i];
			int d2 = array2[i];
			if(d1==d2) {
				flag = true;
				ans = ans + 1;
			}else {
				flag = false;
				ans = 0;
			}

			if(ans==3) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");



	}
}
