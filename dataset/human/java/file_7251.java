import java.util.Scanner;

public class Main {

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] house = new int[n];
		for(int i=0;i<n;i++){
			house[i]=sc.nextInt();
		}
		int maxDist = k-(house[n-1]-house[0]);
		for(int i=0;i<n-1;i++){
			if(house[i+1]-house[i]>maxDist){
				maxDist = house[i+1]-house[i];
			}
		}
		System.out.println(k-maxDist);
	}
}
