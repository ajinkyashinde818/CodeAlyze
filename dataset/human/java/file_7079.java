import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p(long ans) {System.out.println(ans);};
	public static void main(String[] args) {
		int K = sc.nextInt();
		int N = sc.nextInt();
		int max=0;int f1=0;int past1=0;
		
		
		
		for(int i =0;i!=N;i++) {
			int dis = sc.nextInt();
			if(i==0) f1=dis;
			if(dis-past1>max) max=dis-past1;
			past1=dis;
			if(i==N-1) {dis=K-dis+f1;if(dis>max)max=dis;}
		}
		p(K-max);
	}

}
