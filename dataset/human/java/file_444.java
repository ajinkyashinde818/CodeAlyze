import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		sc.close();
		if(n>=10){
			System.out.println(r);
		}else{
			int h = 100*(10-n);
			System.out.println(r+h);
		}
	}
}
