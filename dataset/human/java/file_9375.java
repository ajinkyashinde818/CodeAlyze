import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int conn = 0;
		int cmax = 0;
		for(int i = 0 ; i < N ; ++i){
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a == b){
				conn++;
				cmax = Math.max(cmax, conn);
			}else{
				conn = 0;
			}
		}
		if(cmax >= 3){
			System.out.println("Yes");
		}else{
			System.out.println("No");			
		}
	}
}
