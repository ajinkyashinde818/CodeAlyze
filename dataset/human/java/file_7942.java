import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws java.io.IOException {
		Scanner scan = new Scanner(System.in);
		int s[] = new int[10];
		int sam = 0;
		for(int i = 0; i<10 ;i++){
			s[i] = scan.nextInt();
			sam += s[i];
		}
		System.out.println(sam);
	}
}
