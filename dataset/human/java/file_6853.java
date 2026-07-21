import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int circumference = sc.nextInt(); //円周
		int numOfHouses = sc.nextInt();
		int[] distance = new int[numOfHouses];
		for (int i = 0; i < numOfHouses; i++) {
			distance[i] = sc.nextInt();
		}
		
		int longestDistance = 0;
		for (int i = 2; i < numOfHouses; i++) {
			int tmp = distance[i] - distance[i - 1];
			if (tmp > longestDistance) {
				longestDistance = tmp;
			}
		}
		
		System.out.println(Math.min(distance[numOfHouses - 1] - distance[0], circumference - longestDistance));
	}
}
