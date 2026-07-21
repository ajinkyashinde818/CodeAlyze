import java.util.Scanner;

public class Main {

	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] houseInfo = new int[n];
		for(int i =0; i < n;i++ ) {
			houseInfo[i] = sc.nextInt();
		}

		int[] kyoriInfo = new int[n];
		for(int i =0; i < n;i++ ) {
			if(i == n -1) {
				kyoriInfo[i] = k - houseInfo[i] + houseInfo[0];
			}else {
				kyoriInfo[i] = houseInfo[i+1] - houseInfo[i];
			}
		}
		int answer = 0;
		int max = 0;
		for(int i =0; i < n;i++ ) {
			answer += kyoriInfo[i];
			if(max <  kyoriInfo[i]) {
				max = kyoriInfo[i];
			}
		}
		System.out.println(answer -max);
	}
}
