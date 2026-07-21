import java.util.Scanner;


public class Main {
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		//100 50 4 なら1 2 5　10 25 50 の 5
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c;
		int k = scanner.nextInt();
		
		if(a>b) c=a;
		else    c=b;
		for(int i=c;i>=1;i--) {
			if(a%i==0 && b%i==0) {
				--k;
				if(k==0) {
					System.out.println(i);
				}
			}
		}
	}
}
