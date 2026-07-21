import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int cnt = 0;
		for(int i = Math.min(a,b); i >= 1; i--){
			if(a%i == 0 && b%i == 0){
				cnt += 1;
				if(cnt == k){
					System.out.println(i);
					break;
				}
			}
		}
	}
}
