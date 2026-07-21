import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt(),s=sc.nextInt(),ans=0;
		for(int i=0;i<=k;i++) {
			for(int j=0;j<=k;j++) {
				int num=s-i-j;
				if(0<=num&&num<=k)ans++;
			}
		}
		System.out.println(ans);
		sc.close();
	}
}
