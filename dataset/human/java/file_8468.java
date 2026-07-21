import java.util.HashMap;
import java.util.Scanner;

class Main{
	static int []par;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//文字の入力
		int N = sc.nextInt();
		int K = sc.nextInt();
		int L = sc.nextInt();
		par = new int[N];
		for(int i = 0;i < N;i++){
			par[i] = i;					//初期化
		}
		for(int i = 0;i < K;i++){					//unionfind木の作成
			int p = sc.nextInt() -1;
			int q = sc.nextInt() -1;
			unite(p, q);
		}
		
		int[] road = new int[N];
		for(int i  = 0;i < N;i++){
			road[i] = root(i);					//さっきparで作ったunionfind木をroadとしてコピー
		}
		
		for(int i = 0;i < N;i++){
			par[i] = i;					//初期化
		}
		for(int i = 0;i < L;i++){					//unionfind木の作成
			int r = sc.nextInt() -1;
			int s = sc.nextInt() -1;
			unite(r, s);
		}
		
		int[] rail = new int[N];
		for(int i  = 0;i < N;i++){
			rail[i] = root(i);					//さっきparで作ったunionfind木をroadとしてコピー
		}
		
		HashMap<Long, Integer> map = new HashMap<Long,Integer>();
		for(int i  =0;i < N;i++){
			long g  =(long)N * (long)road[i] + (long)rail[i];				//road,railの親のーどを見ることで、同じだったらカウントを
			if(map.containsKey(g)){
				map.put(g, map.get(g)+1);
			}else{
				map.put(g, 1);
			}
		}
		for(int i = 0; i < N; i++) {					//答え
		      int ans = map.get((long)N * (long)road[i] + (long)rail[i]);
		      if(i == N - 1) {
		        System.out.print(ans);
		      } else {
		        System.out.print(ans + " ");
		      }
		}
				
		
		
	}
	static int root(int x){				//親ノードを見つける
		if(x == par[x]){
			return x;
		}
		return par[x]  = root(par[x]);
	}
	
	
	static void unite(int x,int y){					//結合
		int rootx = root(x);
		int rooty = root(y);
		if(rootx != rooty){
			par[rootx] = rooty;
		}
	}
}
