import java.util.Scanner;

 
public class Main {
 
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] array = new int [n];
		
		for(int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		
		int lastDistance = k - array[n - 1] + array[0];
		int longest = lastDistance;
		for(int i = 0; i < n - 1; i++) {
			int distance = array[i + 1] - array[i];
			if(longest < distance) {
				longest = distance;
			}
		}
		
		System.out.println(k - longest);
		sc.close();
		
	}
	
}
