import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			int k = sc.nextInt();
			int s = sc.nextInt();
			int count = 0;
			for(int x = 0 ; x <= k ; x++) {
				for(int y = 0; y <= k ; y++) {
					int z = s - x -y;
					if(z <= k && 0 <= z ) {
						count++;
					}
				}
			}
			System.out.println(count);
		}
	}
}
