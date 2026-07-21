import java.util.Scanner;

public class Main {
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int n = sc.nextInt();

		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];

		for(int i =0 ; i<n;i++) {
			a[i] = sc.nextInt();
		}
		for(int i =0 ; i<n;i++) {
			b[i] = sc.nextInt();
		}
		for(int i =0 ; i<n-1;i++) {
			c[i] = sc.nextInt();
		}
		c[n-1]=0;

		int sum = 0;
		int lastone = -1;
		for(int i =0;i<n;i++) {
			sum+=b[a[i]-1];
			if(lastone+1==a[i]) {
				sum+=c[lastone-1];
			}
			lastone=a[i];
		}


		System.out.println(sum);
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
