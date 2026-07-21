import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int INF = Integer.MAX_VALUE;

		while(true){
			int m = sc.nextInt();
			int n = sc.nextInt();
			int k = sc.nextInt();
			int d = sc.nextInt();
			if(m == 0) break;

			int[] cake = new int[m];
			for(int i=0;i<m;i++)
				cake[i] = sc.nextInt();

			//[0]:X^[g
			//[1]~[m]:P[L®
			//[m+1]~[m+n]:h}[N
			//[m+n+1]:sð
			int[][] map = new int[m+n+2][m+n+2];
			for(int[] tmp : map) Arrays.fill(tmp,INF);

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

				map[from][to] = map[to][from] = k * cost;
			}

			PriorityQueue<State> open = new PriorityQueue<State>();
			int[][] closed = new int[m+n+4][1000];
			for(int[] tmp : closed) Arrays.fill(tmp,INF);
			int ans = INF;
			open.add(new State(0,0,0));

			while(!open.isEmpty()){
				State st = open.poll();
				if(closed[st.id][st.used] <= st.cost) continue;
				closed[st.id][st.used] = st.cost;

				if(st.id == m+n+1){
					ans = Math.min(ans,st.cost);
				}

				for(int i=0;i<m+n+2;i++){
					if(map[st.id][i] != INF && ( i<1 || m<i || (st.used & (1<<i)) == 0 ) ){
						int ncost = st.cost + map[st.id][i];
						int nused = st.used;
						if(1 <= i && i <= m){
							ncost -= cake[i-1];
							nused |= (1<<i);
						}
						if(closed[i][nused] > ncost)
							open.add(new State(ncost,i,nused));
					}
				}
			}

			System.out.println(ans);
		}
	}
}

class State implements Comparable<State>{
	int cost,id,used;

	State(int cost,int id,int used){
		this.cost = cost;
		this.id = id;
		this.used = used;
	}

	public int compareTo(State st){
		return this.cost - st.cost;
	}
}
