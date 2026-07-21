import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n=scan.nextInt();
		int[] a=new int[n];
		int ans=0;
		for(int i=0;i<n;i++){
			a[i]=scan.nextInt();
		}
		
		Arrays.sort(a);
		
		for(int i=0;i<n;i++){
			if(a[i]>=n-i){
				ans=n-i;
				break;
			}
		}
		System.out.println(ans);
	}
}
