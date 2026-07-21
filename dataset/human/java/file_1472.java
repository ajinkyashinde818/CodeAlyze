import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			int N = scan.nextInt();
			int M = scan.nextInt();
			char[][]n = new char[N][N];
			char[][]m = new char[M][M];
			
			for(int i = 0;i<N;i++) {
				String s = scan.next();
				n[i] = s.toCharArray();
			}
			
			for(int i = 0;i<M;i++) {
				String string = scan.next();
				m[i]=string.toCharArray();
			}
			
			for(int i = 0;i<N-M+1;i++) {
				for(int j = 0;j<N-M+1;j++) {
					int count = 0;
					for(int z = 0;z<M;z++) {
						for(int w = 0;w<M;w++) {
							if(m[z][w]==n[i+z][j+w]) {
								count++;
							}
						}
					}
					
					if(count==M*M) {
						System.out.println("Yes");
						System.exit(0);
					}
					
					
				}
			}
			
			System.out.println("No");
			
			
			
		}
		
		
	}
		

}
