import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int k = sc.nextInt();
	int n = sc.nextInt();
	int[] a = new int[n];
	for(int i=0;i<n;i++) a[i] = sc.nextInt();

	int meter = 0;
	int maxmeter = a[0]+( k-a[n-1] );
	for(int i=0;i<n-1;i++){
	    meter = a[i+1]-a[i];
	    if(meter > maxmeter) maxmeter = meter;
	}

	System.out.print(k-maxmeter);
    }
}
