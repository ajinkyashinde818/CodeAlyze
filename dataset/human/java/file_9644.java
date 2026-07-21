import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] array1 = new int[n];
		int[] array2 = new int[n];
		for(int i = 0; i < n; i++) {
			array1[i] = sc.nextInt();
			array2[i] = sc.nextInt();
		}
		
		boolean ans = false;
		for(int i = 0; i < n - 2; i++) {
			if(array1[i] == array2[i]) {
				if(array1[i+1] == array2[i + 1]) {
					if(array1[i + 2] == array2[i + 2]) {
						ans = true;
						break;
					}
				}
			}
		}
		
		if(ans) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		
		sc.close();
	}
}
