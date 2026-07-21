import java.util.*;

public class Main {
public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in); 
		
		int K = keyboard.nextInt();
		int S = keyboard.nextInt();
		int ans =0;
		
		for(int i = 0; i<=K; i++) {
			for(int j =0; j<=K; j++) {
				if(0 <= S-(i+j) && S-(i+j)<= K) {
					ans++;
				}
			}
		}
		
		System.out.println(ans);
		keyboard.close();	
	}
}
