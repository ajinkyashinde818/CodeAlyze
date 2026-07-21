import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		double sx=sc.nextDouble();
		double sy=sc.nextDouble();
		double gx=sc.nextDouble();
		double gy=sc.nextDouble();
		int n=sc.nextInt();
		double[][] dis=new double[n+2][n+2];
		double[] x=new double[n+2];
		double[] y=new double[n+2];
		double[] r=new double[n+2];
		x[0]=sx;
		y[0]=sy;
		x[1]=gx;
		y[1]=gy;
		for(int i=2;i<n+2; i++){
			x[i]=sc.nextDouble();
			y[i]=sc.nextDouble();
			r[i]=sc.nextDouble();
		}
		for(int i=0; i<n+2; i++){
			for(int j=i+1; j<n+2; j++){
				dis[i][j]=dis[j][i]=Math.max(0,dist(x[i],y[i],x[j],y[j])-r[i]-r[j]);
			}
		}
		
		PriorityQueue<State> q=new PriorityQueue<>();
		boolean[] ch=new boolean[n+2];
		q.add(new State(0,0));
		while(!q.isEmpty()){
			State s=q.poll();
			ch[s.idx]=true;
			if(s.idx==1){
				break;
			}
			for(int i=0; i<n+2; i++){
				if(!ch[i] && dis[0][i]>=s.d+dis[s.idx][i]){
					dis[0][i]=s.d+dis[s.idx][i];
					q.add(new State(i,dis[0][i]));
				}
			}
		}
		System.out.println(dis[0][1]);
	}
	static double dist(double sx,double sy,double gx,double gy){
		return Math.sqrt((sx-gx)*(sx-gx)+(sy-gy)*(sy-gy));
	}
	static class State implements Comparable<State>{
		public int idx;
		public double d;
		public State(int idx,double d){
			this.idx=idx;
			this.d=d;
		}
		@Override
		public int compareTo(State o) {
      		return Double.compare(this.d, o.d);
   		}
	}
}
