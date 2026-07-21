import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        int r = 0;
        int cnt = 0;
        for(int i = Math.min(A, B);1 <= i;i--) {
        	if(A % i == 0 && B % i == 0) {
        		cnt++;
            	if(cnt >= K) {
            		r = i;
            		break;
            	}
        	}
        }
        System.out.println(r);
	}
}
