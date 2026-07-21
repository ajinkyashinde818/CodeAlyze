import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt(),x=sc.nextInt();
		int[] cost = new int[n];
		int[][] array = new int[n][m];
		for(int i=0;i<n;i++) {
			cost[i]=sc.nextInt();
			for(int j=0;j<m;j++) {
				array[i][j]=sc.nextInt();
			}
		}
		int costing=2000000;
		for(int i=0;i<(1<<n);i++) {
			int[] cost_array = new int[m];
			int temp=0;
			for(int j=0;j<n;j++) {
				if((1<<j&i)!=0) {
					temp+=cost[j];
					for(int k=0;k<m;k++) {
						cost_array[k]+=array[j][k];
					}
				}
			}
			int flag=0;
			for(int k=0;k<m;k++) {
				if(cost_array[k]<x) {
					flag=1;
					break;
				}
			}
			if(flag==0) {
				if(costing>temp) {
					costing=temp;
				}
			}
		}
		if(costing==2000000) System.out.println(-1);
		else System.out.println(costing);
	}
}
