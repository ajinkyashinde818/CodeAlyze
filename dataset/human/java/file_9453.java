import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int count = 0;
		boolean flag = false;
		for(int i=0;i<n;i++){
			sc.nextLine();
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			if(a==b){
				count++;
				if(count >= 3){
					flag = true;
					break;
				}
			}else{
				count = 0;
			}
		}
		
		if(flag){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
