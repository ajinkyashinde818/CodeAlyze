import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt(),n=sc.nextInt();
		int[] array = new int[n];
		for(int i=0;i<n;i++) {
			array[i]=sc.nextInt();
		}
		int max=0;
		for(int i=1;i<n;i++) {
			if((array[i]-array[i-1])>=max) {
				max = array[i]-array[i-1];
			}
		}
		if(k-array[n-1]+array[0]>=max) max=k-array[n-1]+array[0];
		System.out.println(k-max);
	}
}
