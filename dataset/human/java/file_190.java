import java.util.Scanner;


public class Main{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		int n=sc.nextInt();
		long a[]=new long[n];
		long total=0;
		long min=1000000000L;
		int count=0;
		for(int i=0;i<n;++i){
			a[i]=sc.nextLong();
			if(Math.abs(a[i])<min)min=Math.abs(a[i]);
			total=total+Math.abs(a[i]);

			if(a[i]<0)++count;
		}

		if (count%2==0)System.out.println(total);
		else System.out.println(total-2*min);
	}
}
