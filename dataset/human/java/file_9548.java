import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int ans = 0;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int hako=0;
		
		for(int i=0;i<n;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			if(a==b) {
				ans++;
				if(ans==3){
					hako=1;
				}
			}
			else {
				ans=0;
			}
		}
		
		if(hako==1) {
			System.out.print("Yes");
		}
		else {
			System.out.print("No");
		}

	}
}
