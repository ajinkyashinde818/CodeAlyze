import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			int K = scan.nextInt();
			int S = scan.nextInt();
			
			
			
			int count = 0;
			
			for(int i = 0;i<=K;i++) {
				for(int j = 0;j<=K;j++) {
					if(S-i-j>=0&&S-i-j<=K)count++;	
				}
			}
			
			
			System.out.println(count);
			
			
			
		}
		
		
	}
	
	
	
	
	
		

}
