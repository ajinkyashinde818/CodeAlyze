import java.util.*;

class Main{
	static public void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int n=sc.nextInt();
		int ans=0;
		int[] an=new int[n+1];
		
		for(int i=0;i<n;i++){
			an[i]=sc.nextInt();
		}
		an[n]=an[0]+k;
		for(int i=0;i<n;i++){
			ans=Math.max(ans,an[i+1]-an[i]);
		}
		int aa=k-ans;
		System.out.println(aa);
	}
}
