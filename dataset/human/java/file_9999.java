import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int guideBook = sc.nextInt();
		int algorithm = sc.nextInt();
		int target = sc.nextInt();
		int[] priceInfo = new int[guideBook];
		int[][] guideBookInfo = new int[guideBook][algorithm];
		for(int i = 0;i < guideBook;i++) {
			priceInfo[i] = sc.nextInt();
			for(int j = 0; j < algorithm;j++) {
				guideBookInfo[i][j] = sc.nextInt();
			}
		}
		int answer = 0;
		for(int i = 0;i < 1 << guideBook;i++) {
			int[] rikaidoInfo = new int[algorithm];
			int price = 0;
			for(int j =0; j < guideBook;j++) {
				if((1 & (i >>j)) ==1) {
					price += priceInfo[j];
					for(int k =0; k < algorithm;k++) {
						rikaidoInfo[k]+= guideBookInfo[j][k];
					}
				}
			}
			for(int j =0; j < algorithm;j++) {
				if(target > rikaidoInfo[j]) {
					break;
				}
				if(j == algorithm -1) {
					if(answer ==0) {
						answer = price;
					}else {
						if(answer > price) {
							answer = price;
						}
					}
				}
			}
		}
		if(answer ==0) {
			System.out.println(-1);
			return;
		}
		System.out.println(answer);
	}
}
