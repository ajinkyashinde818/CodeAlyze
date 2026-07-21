import java.util.Scanner;

class Main{
	static int G;
	static int D;
	static int[] p;
	static int[] c;
	static boolean[] used;
	static long ans = 1000000000;


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//文字の入力
		D = sc.nextInt();
		G = sc.nextInt();
		p = new int[D];
		c = new int[D];
		for(int i = 0;i < D;i++){
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		for(int i = 0;i < D;i++){
			boolean[]used = new boolean[D];
			used[i] = true;
			dfs(i,0,0,used);
		}

		System.out.println(ans);



	}
	static void dfs(int po,int sum,int count,boolean[] used){
		//		System.out.println("sum " + sum );
		//		
		//		System.out.println("used " + used[0] + " 0 " );
		//		System.out.println("used " + used[1] + " 1 " );

		if(sum >= G){
			ans = Math.min(ans, count);
			return;
		}

		for(int i = 0;i < p[po];i++){
			sum += (po+1)*100;
			if(i == p[po]-1){			//ボーナス
				sum += c[po];
			}
			count++;
			if(sum >= G){
				ans = Math.min(ans, count);
				return;
			}
		}


		for(int i = 0;i < D;i++){
			if(!used[i]){
				used[i] = true;
				dfs(i, sum, count,used);
				used[i] = false;
			}
		}



	}


}

class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
}
