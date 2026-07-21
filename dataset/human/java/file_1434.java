import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<String> arr1 = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			arr1.add(sc.next());
		}
		ArrayList<String> arr2 = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			arr2.add(sc.next());
		}
		for(int i = 0; i <= n - m; i++) {
			for(int j = 0; j <= n - m; j++) {//座標の右上を全探索

				for(int k = 0; k < m; k++) {
					if(arr1.get(i+k).substring(j).startsWith(arr2.get(k))) {
						if(k == m - 1) {
							System.out.println("Yes");
							return;
						}
					} else {
						break;
					}
				}

			}
		}
		System.out.println("No");
	}
}
