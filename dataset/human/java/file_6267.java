import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = Integer.parseInt(sc.next());
		int s = Integer.parseInt(sc.next());

		int count = 0;

		for (int x = 0; x <= k; x++) {
			for (int y = 0; y <= k; y++) {
				int z = s - x - y;
				if (0 <= z && z <= k) {
					count++;
				} else if(z < 0){
					break;
				}
			}
		}

		System.out.println(count);
		sc.close();
	}

}
