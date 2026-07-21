import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = 0;
		for(int i = 0 ; i < 10 ;i++){
			int a = sc.nextInt();
			p += a;
		}
		System.out.println(p);
		sc.close();
	}

}
