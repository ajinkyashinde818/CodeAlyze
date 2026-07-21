import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int N = Math.max(A, B);
		int count=0;
		int kekka=0;
		
		for(int i=(Math.min(A, B));i>=1;i--) {
			if(A%i==0 && B%i==0) {
				count++;
				if(count==K) {
					kekka=i;
					break;
				}
			}
		}
		
		System.out.println(kekka);
		
		
		
		sc.close();
	}
}
