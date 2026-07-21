import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
		}
		int count=0;
		boolean boo=true;
		for(int i=0;i<n;i++){
			if(a[i]<0)
				count++;
			else if(a[i]==0)
				boo=false;
		}
		long ans=0;
		for(int i=0;i<n;i++){
			if(a[i]<0)
				a[i]=-a[i];
		}
		for(int i=0;i<n;i++){
			ans+=a[i];
		}
		int m=a[0];
		if(count%2!=0&&boo){
			for(int i=1;i<n;i++){
				if(a[i]<m)
					m=a[i];
			}
			ans=ans-2*m;
		}
		System.out.println(ans);
	}
	
}
