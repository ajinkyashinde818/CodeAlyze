import java.util.Scanner;

public class Main {
	
	int[][] dp;
	int INF = 1001001001;

	public static void main(String[] args) {
		Main mainObj = new Main();
		mainObj.solve();
	}
	
	public void solve() {
		Scanner sc = new Scanner(System.in);
		String price = sc.nextLine();
		sc.close();
		int[] priceArr = new int[price.length()+1];
		for(int i = 0; i < price.length(); i++) {
			priceArr[i] = price.charAt(price.length() - 1 - i) - '0';
		}
		priceArr[price.length()] = 0;
		
		dp = new int[priceArr.length+2][2];
		for(int i = 0; i < dp.length ; i++) {
			for(int j = 0; j < 2; j++) {
				dp[i][j] = INF;
			}
		}
		
		dp[0][0] = 0;
		
		for(int i = 0; i < priceArr.length; i++) {
			for(int j = 0; j < 2 ; j++) {
				int digit = priceArr[i];
				digit = digit + j;
				
				if(digit < 10) {
					dp[i+1][0] = Math.min(dp[i+1][0], dp[i][j] + digit);
				}
				if(digit > 0) {
					dp[i+1][1] = Math.min(dp[i+1][1], dp[i][j] + (10 - digit));
				}
			}
		}
		
		System.out.println(dp[price.length()+1][0]);
		
//		int extraPrice = 0;
//		for(int i = price.length() - 1; i >= 0; i--) {
//			if(priceArr[i] >= 10) {
//				if(i == 0) {
//					extraPrice = priceArr[i] / 10;
//					priceArr[i] = priceArr[i] % 10;
//				}else {
//					priceArr[i - 1] += priceArr[i] / 10;
//					priceArr[i] = priceArr[i] % 10;
//				}
//			}
//			if(priceArr[i] >= 6) {
//				kuriageArr[i] = priceArr[i];
//				if(i == 0) {
//					extraPrice += 1;
//					priceArr[i] = 0;
//				}else {
//					priceArr[i] = 0;
//					priceArr[i - 1] += 1;
//				}
//			}
//		}
//		
//		int ans = extraPrice;
//		for(int i = 0 ; i < price.length(); i++) {
//			int thisPriceArrValue = priceArr[i];
////			int thisPrice = price.charAt(i) - '0';
//			if(kuriageArr[i] > 0) {
//				ans = ans + 10 - kuriageArr[i];
//			}
//			ans += thisPriceArrValue;
// 		}
//		System.out.println(ans);
	}
}
