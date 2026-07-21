import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),i;
		long a,t[]=new long[200000],m=Long.MAX_VALUE;
		for(i=0;i<n;i++) {
			a=sc.nextInt();
			t[i]=a;
			if(0<i) t[i]+=t[i-1];
		}
		sc.close();
		for(i=0;i<n-1;i++) if(m>Math.abs(2*t[i]-t[n-1])) m=Math.abs(2*t[i]-t[n-1]);
		System.out.print(m);
	}
}
