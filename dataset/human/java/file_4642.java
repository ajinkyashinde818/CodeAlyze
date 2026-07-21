import java.util.*;
import java.awt.geom.*;
import static java.lang.Math.*;
public class Main {
	final Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		new Main().init();
	}
	void init(){
		new AOJ1235();
	}
	
	class AOJ1235{
		int N,C;
		int[][] t;
		final int INF=1<<29;
		final int[] vx={-1,-1,0,1,1,0}, vy={0,-1,-1,0,1,1};
		AOJ1235(){
			while(true){
				N=sc.nextInt();
				C=sc.nextInt();
				if(N==0)	break;
				t=new int[N][N];
				for(int x=0; x<N; ++x)for(int y=0; y<N; ++y)	t[x][y]=-1;
				for(int y=0; y<N; ++y)for(int x=0; x<=y; ++x)	t[x][y]=sc.nextInt();
				// debug
//				for(int y=0; y<N; ++y){
//					for(int x=0; x<=y; ++x)	System.out.print(t[x][y]+" ");
//					System.out.println();
//				}
				solve();
			}
		}
		void solve(){
			int ans=-INF;
			boolean[][] vtd=new boolean[N][N];
			for(int y=0; y<N; ++y)for(int x=0; x<=y; ++x)if(t[x][y]==0){
				for(int i=0; i<N; ++i)for(int j=0; j<N; ++j)	vtd[i][j]=false;
				t[x][y]=C;
				int cand = 0;
				boolean m1=true;
				for(int v=0; v<6; ++v){
					int sx=x+vx[v], sy=y+vy[v];
					if(!(0<=sx&&sx<N && 0<=sy&&sy<N))	continue;
					if(t[sx][sy]==C || t[sx][sy]==0)	m1=false;
					if(t[sx][sy]<=0 || vtd[sx][sy])	continue;
					vtd[sx][sy]=true;
					zero=false;
					int ret = dfs(sx, sy, vtd);
					cand += (zero? 0 : (t[sx][sy]==C? -ret : ret));
				}
				// debug
//				System.out.println("cand"+cand);
				ans = max(ans, cand+(m1? -1:0));
				t[x][y]=0;
			}
			System.out.println(ans);
		}
		boolean zero;
		int dfs(int x,int y,boolean[][] vtd){
			int ret=1;
			for(int v=0; v<6; ++v){
				int xx=x+vx[v], yy=y+vy[v];
				if(!(0<=xx&&xx<N && 0<=yy&&yy<N))	continue;
				if(vtd[xx][yy])	continue;
				if(t[xx][yy]<0)	continue;
				if(t[xx][yy]==0){
					zero=true;
					continue;
				}
				if(t[xx][yy]!=t[x][y])	continue;
				vtd[xx][yy]=true;
				ret += dfs(xx,yy,vtd);
			}
			return ret;
		}
	}
}
