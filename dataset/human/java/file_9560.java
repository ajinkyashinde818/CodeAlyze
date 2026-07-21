import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		int b[]=new int[n];
		boolean flag=false;
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
		}
		int count=0;
		for(int i=0;i<n;i++) {
			if(a[i]==b[i]) {
				count++;
				if(count==3) {
					flag=true;
					break;
				}
			}
			else {
				count=0;
			}
		}
		if(flag)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
