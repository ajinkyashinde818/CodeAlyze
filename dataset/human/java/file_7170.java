import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int k = scan.nextInt();
		int n = scan.nextInt();
		int[] house = new int[n];
		for(int i = 0; i < n; i++) {
			house[i] = scan.nextInt();
		}
		
		int maxDist = k - (house[n-1] - house[0]);
		for(int i = 0; i < n-1; i++) {
			if(house[i+1]-house[i] > maxDist) maxDist = house[i+1]-house[i];
		}
		
		System.out.println(k-maxDist);
	}

}
