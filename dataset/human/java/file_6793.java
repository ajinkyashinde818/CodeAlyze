import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int dist = scan.nextInt();
		int home = scan.nextInt();
		int[] kyori = new int[home];
 		
		for(int i = 0; i < home;i++) {
			kyori[i] = scan.nextInt();
			
		}
		
		int min = Math.min(kyori[home -  1] - kyori[0] , dist - kyori[1] + kyori[0]);
		min = Math.min(min, dist - kyori[home - 1] + kyori[home - 2]);
		
		for(int i = 1;i < home - 1 ; i++) {
		min = Math.min(min, Math.min(dist - kyori[i] + kyori[i - 1], dist - kyori[i + 1] + kyori[i]));
		
		}
		
		System.out.println(min);
		
	}
	
}
