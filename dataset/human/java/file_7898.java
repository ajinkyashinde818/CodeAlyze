import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class Main{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-12;

	int n;
	String[] lines;

	void run(){
		n=sc.nextInt();
		sc.nextLine();
		lines=new String[n];
		for(int i=0; i<n; i++){
			lines[i]=sc.nextLine();
		}
		solve();
	}

	void solve(){
		for(int i=0; i<n; i++){
			lines[i]=lines[i].substring(0, lines[i].length()-1);
		}
		int[] next=new int[n];
		for(int i=0; i<n; i++){
			String[] ss=lines[i].split(" ");
			if(ss.length==2){
				String label=ss[1];
				for(int j=0; j<n; j++){
					if(lines[j].equals(label)){
						next[i]=j;
					}
				}
			}else{
				next[i]=i+1;
			}
		}
		int[] d=new int[n+1];
		fill(d, INF);
		d[0]=0;
		LinkedList<Integer> que=new LinkedList<Integer>();
		que.addLast(0);
		for(; !que.isEmpty();){
			int v=que.poll();
			if(v==n){
				continue;
			}
			if(d[v]<d[next[v]]){
				d[next[v]]=d[v];
				que.addFirst(next[v]);
			}
			if(d[v]+1<d[v+1]){
				d[v+1]=d[v]+1;
				que.addLast(v+1);
			}
		}
//		debug(d);
		println(d[n]+"");
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
		new Main().run();
	}
}
