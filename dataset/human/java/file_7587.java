import java.util.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		var k=s.nextLong();
		var a=new int[n];
		var b=new long[n];
		Arrays.setAll(a,i->s.nextInt()-1);

		var i=0;
		for(int t=1;k >= 0;--k,++t,i=a[i]){
			if(b[i]>0)
				k%=t-b[i];
			b[i]=t;

			if(k==0L){
				System.out.println(i+1);
				return;
			}
		}
	}
}
