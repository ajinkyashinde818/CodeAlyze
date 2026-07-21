import java.util.Scanner;

class Main {
	public static void main(String[] $) {
		Scanner sc = new Scanner(System.in);
		int k=sc.nextInt(),n=sc.nextInt();
		int max=Integer.MIN_VALUE;
		int[] a=new int[n];
		a[0]=sc.nextInt();
		for(int i=1;i<n;i++) {
			a[i]=sc.nextInt();
			max=Math.max(max, Math.abs(a[i]-a[i-1]));
		}
		max=Math.max(max, a[0]+k-a[n-1]);
		System.out.println(k-max);
		//System.out.println(max);
	}
}
