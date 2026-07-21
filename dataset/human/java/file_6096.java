import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int count = 0;
		int k = sc.nextInt();
		int s = sc.nextInt();
		for(int x = 0; x <= k; x++) {
			for(int y = 0; y <= k; y++) {
				int z = s - x - y;
				if(0 <= z && z <= k) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}
