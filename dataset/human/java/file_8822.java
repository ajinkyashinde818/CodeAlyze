import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int k = scanner.nextInt();
		int tmp = 0;
		int[] ary = new int[k];
		for(int n=100; n>0; n--) {
			if(a%n==0 && b%n==0) {
				ary[tmp]= n;
				tmp++;
			}
			
			if(tmp==k)break;
		}
		System.out.println(ary[k-1]);
	}

}
