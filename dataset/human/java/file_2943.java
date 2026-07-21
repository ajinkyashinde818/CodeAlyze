import java.util.ArrayList;
import java.util.Scanner;

class Main{

	static int N;
	static int M;
	static 		ArrayList<ArrayList<Integer>> map;



	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);			//文字の入力
		N = sc.nextInt();
		M = sc.nextInt();
		map = new ArrayList<ArrayList<Integer>>(200001);

		for(int i = 0;i <200000;i++){				//初期化
			ArrayList<Integer> set = new ArrayList<Integer>();
			set.add(0);
			map.add(set);
		}

		for(int  i = 0;i < M;i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			map.get(a).add(b);
		}

		dfs(1,0);
		System.out.println("IMPOSSIBLE");


	}

	static void dfs(int p, int count){				//pは現在地、cは何回定期便を使ったか

		if(count > 2){
			return;
		}

		if(p == N){
			System.out.println("POSSIBLE");
			System.exit(0);
		}

		for(int i= 0;i < map.get(p).size();i++){
			int nextp = map.get(p).get(i);					//隣接点
			count++;
			dfs(nextp, count);					
			count--;
		}

	}

}
