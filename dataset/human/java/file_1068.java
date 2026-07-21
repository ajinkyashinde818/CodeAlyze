import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

// AC
public class Main{

	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int n, m;
	P[] cs;
	int[] rs;
	P t, s;

	void run(){
		for(;;){
			n=sc.nextInt();
			if(n==0){
				break;
			}
			cs=new P[n];
			rs=new int[n];
			for(int i=0; i<n; i++){
				int x=sc.nextInt();
				int y=sc.nextInt();
				rs[i]=sc.nextInt();
				cs[i]=new P(x, y);
			}
			m=sc.nextInt();
			for(int i=0; i<m; i++){
				int tx=sc.nextInt();
				int ty=sc.nextInt();
				int sx=sc.nextInt();
				int sy=sc.nextInt();
				t=new P(tx, ty);
				s=new P(sx, sy);
				solve();
			}
		}
	}

	void solve(){
		boolean safe=false;
		for(int i=0; i<n; i++){
			P[] ps=isCL(cs[i], rs[i], t, s);
			for(P p : ps){
				if(between(t.x, s.x, p.x)&&between(t.y, s.y, p.y)){
					safe=true;
				}
			}
		}
		println(safe?"Safe":"Danger");
	}

	boolean between(double x1, double x2, double x){
		return (x1<x+EPS&&x<x2+EPS)||(x1+EPS>x&&x+EPS>x2);
	}

	P[] isCL(P c, double r, P p1, P p2){
		double x=p1.sub(c).dot(p2.sub(p1));
		double y=p2.sub(p1).abs2();
		double d=x*x-y*(p1.sub(c).abs2()-r*r);
		if(d<-EPS)
			return new P[0];
		if(d<0)
			d=0;
		P q1=p1.sub(p2.sub(p1).mul(x/y));
		P q2=p2.sub(p1).mul(Math.sqrt(d)/y);
		return new P[]{q1.sub(q2), q1.add(q2)};
	}

	class P{
		double x, y;

		P(){
			this(0, 0);
		}

		P(double x, double y){
			this.x=x;
			this.y=y;
		}

		P add(P p){
			return new P(x+p.x, y+p.y);
		}

		P sub(P p){
			return new P(x-p.x, y-p.y);
		}

		P mul(double m){
			return new P(x*m, y*m);
		}

		P div(double d){
			return new P(x/d, y/d);
		}

		double abs(){
			return Math.sqrt(abs2());
		}

		double abs2(){
			return x*x+y*y;
		}

		double arg(){
			return Math.atan2(y, x);
		}

		// inner product
		double dot(P p){
			return x*p.x+y*p.y;
		}

		// outer product
		double det(P p){
			return x*p.y-y*p.x;
		}

		P rot90(){
			return new P(-y, x);
		}

		// conjugation
		P conj(){
			return new P(x, -y);
		}
	}

	void debug(Object... os){
		System.err.println(Arrays.deepToString(os));
	}

	void print(String s){
		System.out.print(s);
	}

	void println(String s){
		System.out.println(s);
	}

	public static void main(String[] args){
		// System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		new Main().run();
	}
}
