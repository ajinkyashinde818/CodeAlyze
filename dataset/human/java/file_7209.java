import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc=new Scanner(System.in);
		
		int k=sc.nextInt();		//円形の湖
		int n=sc.nextInt();		//n軒の家
		
		int[]a=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}

		int count=0;
		int ans=a[0]+(k-a[n-1]);
		for(int i=0;i<n-1;i++) {
			count=a[i+1]-a[i];
			if(count>ans) {
				ans=count;
			}
		}
		System.out.println(k-ans);
		sc.close();
	}

}
