import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		int[] order = new int[N];
		for (int i = 0; i < N; i++) {
			order[i] = scan.nextInt();
		}
		
		int[] satisfaction = new int[N];
		for (int i = 0; i < N; i++) {
			satisfaction[i] = scan.nextInt();
		}
		
		int[] addSatisfaction = new int[N];
		for (int i = 0; i < N - 1; i++) {
			addSatisfaction[i] = scan.nextInt();
		}
		
		int total = 0;
		for (int i = 0; i < order.length; i++) {
			total += satisfaction[order[i] - 1];

          	if (i == 0) {
              continue;
            }
          
			if (order[i - 1] + 1 == order[i]) {
				total += addSatisfaction[order[i - 1] - 1];
			}
		}

		System.out.println(total);
	}
}
