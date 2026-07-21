import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int k=sc.nextInt();
		int t=sc.nextInt();
		int count=0;
		for(int i=0;i<=k&&i<=t;i++) {
			for(int j=0;j<=k&&i+j<=t;j++) {
				if(t-(i+j)<=k)count++;
			}
		}
		System.out.println(count);
	}
}
