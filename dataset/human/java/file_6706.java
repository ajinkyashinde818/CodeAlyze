import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		int[] d=new int[n];
		for(int i=0;i<n-1;i++){
			d[i]=a[i+1]-a[i];
		}
		d[n-1]=k-(a[n-1]-a[0]);
		Arrays.sort(d);
		System.out.println(k-d[n-1]);
	}
}
