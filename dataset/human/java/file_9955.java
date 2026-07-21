import java.util.Scanner;

public class Main {

	static long bignum = 1000000000+7;

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int[] c = new int[n];
		int[][] a = new int[n][m];

		int[] sumR = new int[m];
		for(int i =0;i<m;i++) {
			sumR[i] =0;
		}

		for(int i=0;i<n;i++) {
			c[i]=sc.nextInt();
			for(int j=0;j<m;j++) {
				a[i][j]=sc.nextInt();
				sumR[j]+=a[i][j];
			}
		}
		boolean flag = true;
		for(int i =0;i<m;i++) {
			if(sumR[i]<x) {
				flag = false;
				break;
			}
		}
		if(flag) {
			int minCost = 100000000;

			for(int i=0;i<(1<<n);i++) {
				boolean[] bits = new boolean[n];
				int cost = 0;
				for(int j=0;j<m;j++) {
					sumR[j]=0;
				}
				for(int j=0;j<n;j++) {
					if ((1 & i>>j) == 1) {
						bits[j]=true;
						cost+=c[j];
						for(int k=0;k<m;k++) {
							sumR[k]+=a[j][k];
						}
					}else {
						bits[j]=false;
					}
				}
				boolean check = true;
				for(int j=0;j<m;j++) {
					if(x>sumR[j]) {
						check = false;
						break;
					}
				}
				if(check) {
					if(minCost>cost) {
						minCost = cost;
					}
				}
			}
			System.out.println(minCost);

		}else {
			System.out.println(-1);
		}




	}

	static long divn(int target, int times) {//10_9+7のあまり累乗版
		int sqtimes = (int)Math.sqrt(times);
		long ans = 1;
		for(int i =0;i<sqtimes;i++) {
			ans = (ans * target)%(1000000000+7);
		}
		long holder = ans;
		ans = 1;
		for(int i =0;i<sqtimes;i++) {
			ans = (ans*holder)%(1000000000+7);
		}
		for(int i=0;i<times - sqtimes*sqtimes;i++) {
			ans = (ans * target)%(1000000000+7);
		}
		return ans;
	}

	static long div(long a) {//10_9+7のあまり
		if(a<0)a+=1000000000+7;
		return a%(1000000000+7);
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
