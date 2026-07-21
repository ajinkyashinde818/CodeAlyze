import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	static class State implements Comparable<State>{
		int cost,id,used;

		State(int cost,int id,int used){
			this.cost = cost;//最小カロリー
			this.id = id;//頂点
			this.used = used;//通ってきたケーキ屋の状態
		}

		public int compareTo(State st){
			return this.cost - st.cost;
		}
	}

	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			while(sc.hasNext()) {
				int INF=Integer.MAX_VALUE;
				int m = sc.nextInt();
				int n = sc.nextInt();
				int k = sc.nextInt();
				int d = sc.nextInt();
				if(m == 0) break;

				int[] cake = new int[m];
				for(int i=0;i<m;i++) {//i+1のケーキ屋のカロリー
					cake[i] = sc.nextInt();
				}

				//[0]:スタート
				//[1]~[m]:ケーキ屋
				//[m+1]~[m+n]:ランドマーク
				//[m+n+1]:市役所
				int[][] edge = new int[m+n+2][m+n+2];
				for(int i=0; i<m+n+2; i++) {
					for(int j=0; j<m+n+2; j++) {
						edge[i][j]=INF;
					}
				}

				for(int i=0;i<d;i++){
					String a = sc.next();
					String b = sc.next();
					int cost = sc.nextInt();
					int from=-1,to=-1;

					if(a.equals("H")) from = 0;
					else if(a.equals("D")) from = m+n+1;
					else if(a.charAt(0) == 'C') from = Integer.parseInt(a.substring(1));
					else from = m + Integer.parseInt(a.substring(1));

					if(b.equals("H")) to = 0;
					else if(b.equals("D")) to = m+n+1;
					else if(b.charAt(0) == 'C') to = Integer.parseInt(b.substring(1));
					else to = m + Integer.parseInt(b.substring(1));

					edge[from][to] = edge[to][from] = k * cost;
				}

				PriorityQueue<State> open = new PriorityQueue<State>();
				int[][] dis = new int[m+n+4][1<<m];//dis[今の頂点][通ってきたケーキ屋の状態]=最小カロリー
				for(int i=0; i<m+n+2; i++) {
					for(int j=0; j<(1<<m); j++) {
						dis[i][j]=INF;
					}
				}
				int ans = INF;
				open.add(new State(0,0,0));

				while(!open.isEmpty()){
					State st = open.poll();
					if(dis[st.id][st.used] <= st.cost) continue;
					dis[st.id][st.used] = st.cost;

					if(st.id == m+n+1){
						ans = Math.min(ans,st.cost);
					}

					for(int i=0;i<m+n+2;i++){     //start||ケーキ屋じゃない||通ってないケーキ屋
						if(edge[st.id][i] != INF && ( i==0 || i>m || (st.used & (1<<(i-1))) == 0 ) ){
							int ncost = st.cost + edge[st.id][i];
							int nused = st.used;
							if(1 <= i && i <= m){//ケーキ屋なら
								ncost -= cake[i-1];//ケーキ分のカロリー
								nused |= (1<<(i-1));//ケーキ屋きた状態に
							}
							open.add(new State(ncost,i,nused));
						}
					}
				}

				System.out.println(ans);
			}
			
		}
	}
}
