import java.util.*;


class Main{
	public static void main(String args[]){
		
		Scanner sc=new Scanner(System.in);
		
		int k=sc.nextInt();
		int n=sc.nextInt();
		
		if(n==1){
			System.out.println(k);
			System.exit(0);
		}
		
		int a[]=new int[n];
		
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
		}
		
		int max=0;
		for(int i=1;i<n;i++){
			if(i==n-1){
				if(max<k-a[i]+a[0])max=k-a[i]+a[0];
			}
			if(max<a[i]-a[i-1])max=a[i]-a[i-1];
		}
		
		System.out.println(k-max);
		
		
	}
}
