import java.util.Scanner;

public class Main{
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		
		if (A >=10){
			System.out.print(B);
			
		}else {
			int t = 100*(10-A);
			int x = (B+t);
			System.out.print(x);
		}
		
		

	}
}
