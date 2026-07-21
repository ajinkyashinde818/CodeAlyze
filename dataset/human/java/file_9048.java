import java.util.ArrayList;
import java.util.Scanner;
class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//文字の入力



		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int mod = 1000000007;
		for(int i = 0;i < m;i++){
			a[i] = sc.nextInt();
		}
		int[] dp = new int[n+1];
		dp[0] = 1;
		for(int i = 0;i < m;i++){
			dp[a[i]] = -1;
		}
		for(int i = 0;i <= n;i++){
			if(dp[i] >= 0){
				if(i + 1 <= n && dp[i + 1] >= 0){
					dp[i + 1] += dp[i]%mod;
				}
				if(i + 2 <= n && dp[i + 2] >= 0){
					dp[i + 2] += dp[i]%mod;
				}
			}
		}
		System.out.print(dp[n]%mod);




	}


	static boolean checkswitch(int bit,int[] k,ArrayList<ArrayList<Integer>> list,int[] p,int m){

		//		System.out.println("bit " + bit);

		for(int i = 0;i < m;i++){

			ArrayList<Integer> sub = list.get(i);
			int onnum = 0;						//onの数
			for(int j = 0;j < sub.size();j++){
				//				System.out.println("sub "+ sub.get(j));
				if((bit & (1 << sub.get(j))) != 0){				//目的のスイッチがついているか
					onnum++;
					//					System.out.println("on  ");
				}

			}
			if(onnum % 2 != p[i]){				//一個でも電球がつかなかったらout
				return false;
			}

		}


		return true;

	}

	static int gcd(int a,int b){				//最大公約数を返す
		if(b == 0){
			return a;
		}else{
			return gcd(b, a%b);
		}
	}





}



class Pair implements Comparable{
	int from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return  otherpair.end - end;
	}
}
