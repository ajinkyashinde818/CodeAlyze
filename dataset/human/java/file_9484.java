import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] $) {
		new Main().run();
	}
	
	void run() {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		boolean ans=false;
		int[][] D=new int[N][2];
		for (int i=0;i<N;++i) {
			D[i][0]=sc.nextInt();
			D[i][1]=sc.nextInt();
		}
		for (int i=0;i+2<N;++i) {
			ans|=D[i][0]==D[i][1]&&D[i+1][0]==D[i+1][1]&&D[i+2][0]==D[i+2][1];
		}
		System.out.println(ans?"Yes":"No");
	}
	
	void tr(Object...objects) {System.out.println(Arrays.deepToString(objects));}
}
