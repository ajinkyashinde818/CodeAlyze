import java.util.Scanner;

class Main {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n;
		int ans = 0;
		
		for(int i = 0; i < 10; i++){
			n = scan.nextInt();
			ans += n;
		}
		System.out.println(ans);
	}
}
