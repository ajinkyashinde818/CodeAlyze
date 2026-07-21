import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int n = scan.nextInt();
		int a[]=new int[n],ans=Integer.MAX_VALUE;
		for(int i=0;i<n;i++){a[i]=scan.nextInt();}
		scan.close();

		for(int i=0;i<n;i++) {
			int right = a[n-1]-a[i];
			if(i!=0)right+=a[i-1]+k-a[n-1];
			int left = a[i];
			if(i!=n-1)left+=k-a[i+1];

			if(ans>right)ans=right;
			if(ans>left)ans=left;
		}
		System.out.println(ans);
	}
}
