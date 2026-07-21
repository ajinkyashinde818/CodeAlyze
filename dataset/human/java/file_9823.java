import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int[] c = new int[n+1];
		int[][] a= new int[n+1][m+1];

		for (int i=1; i<=n; i++){
			c[i] = sc.nextInt();
			for (int j=1; j<=m; j++){
				a[i][j] = sc.nextInt();
			}
		}

		ArrayList<ArrayList<Integer>>buyList = new ArrayList<ArrayList<Integer>>();

		for (int i=1; i<=n; i++){

			if (i==1){
				for (int l=1; l<= n; l++){
					buyList.add(new ArrayList<>(Arrays.asList(l)));
				}
			} else {

				for (int j = 0; j<buyList.size(); j++){
					ArrayList<Integer> push = buyList.get(j);
					if (push.size() == i-1){
						int lastNum = push.get(i-2);
						for (int k = lastNum+1; k<=n; k++){
							ArrayList<Integer> newList = (ArrayList<Integer>) push.clone();
							newList.add(k);
							buyList.add(newList);
						}
					}
				}
			}

		}

		int ans = Integer.MAX_VALUE;
		for (int i=0; i < buyList.size(); i++){
			int[] rikaido = new int[m+1];
			int money = 0;
			ArrayList<Integer> buy = buyList.get(i);

			for (int j=0; j<buy.size(); j++){
				int sankosyo = buy.get(j);
				money += c[sankosyo];
				for (int k=1 ; k<=m; k++){
					rikaido[k] += a[sankosyo][k];
				}
			}

			boolean result = true;

			for (int l=1; l<=m; l++){
				if (rikaido[l] < x){
					result = false;
					break;
				}
			}
			if (result){
				ans = Math.min(ans, money);
			}
		}

		if (ans == Integer.MAX_VALUE){
			ans = -1;
		}

		System.out.println(ans);
	}


}
