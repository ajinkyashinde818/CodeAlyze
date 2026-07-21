import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(),B=sc.nextInt(),K=sc.nextInt();
		int min = Math.min(A, B);
		int count=0;
		for(; min>0; min--) {
			if(A%min==0 && B%min==0) {
				count++;
				if(count==K)break;
			}
		}
		System.out.println(min);
	}
}
