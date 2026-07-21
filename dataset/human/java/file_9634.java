import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int[][] d = new int[n][2];
		
		int count = 0;
		for(int i = 0; i < n; i++) {
			d[i][0] = sc.nextInt();
			d[i][1] = sc.nextInt();
			
			if(d[i][0] == d[i][1]) {
				count++;
			}else {
				count = 0;
			}
			
			if(count == 3) {
				System.out.println("Yes");
				break;
			}
			
		}
		
		if(count != 3) System.out.println("No");
		
		
		
		
	}

}
