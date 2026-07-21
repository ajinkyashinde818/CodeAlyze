import java.util.Scanner;

public class Main {

	static long bignum = 1000000000+7;

	public static int[] rudder = new int[200001];

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);


		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		int max = 1;
		for(int i=0;i<n-1;i++) {
			if((a[i+1]-a[i])>max)max = (a[i+1]-a[i]);
		}
		if((a[0]+k-a[n-1])>max)max = (a[0]+k-a[n-1]);
		System.out.println(k-max);
	}





}
/*
class City{
	int order;
	int prefecture;
	int year;
	int number;
	City(int order,int prefecture, int year){
		this.order = order;
		this.prefecture = prefecture;
		this.year = year;
	}
}
*/
