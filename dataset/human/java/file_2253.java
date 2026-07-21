import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			int N=sc.nextInt();
			int a, b;
			int[] d=new int[100010];
			for(int i=0; i<N; i++) {
				a=sc.nextInt();
				b=sc.nextInt();
				for(int j=a-1; j<=b-1; j++) {
					d[j]++;
				}
			}
			int ans=0;
			for(int i=0; i<=100001; i++) {
				if(i<=d[i]) {
					ans=i;
				}
			}
			System.out.println(ans);
		}
	}
}
