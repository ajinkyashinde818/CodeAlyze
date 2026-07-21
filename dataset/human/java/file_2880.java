import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main {

	int INF = 1 << 28;
	void run() {
		Scanner sc = new Scanner(System.in);
		int horse[] = {4, 1, 4, 1, 2, 1, 2, 1};
		int ans[] = {7,2,6,0,4,1,5,3};
		while(sc.hasNext()) {
			int[] human = new int[8];
			int maxhuman = 0;
			for(int i=0;i<8;i++) {
				human[i] = sc.nextInt();
				maxhuman += human[i];
			}
			int minhuman = maxhuman;
			int p=0;
			for(int i=0;i<8;i++) {
				int sum = 0;
				for(int j=0;j<8;j++) {
					sum += human[j] - min(horse[(i+j)%8], human[j]);
				}
				if(minhuman > sum ) {
					 p = i;
					minhuman = sum;
				}
				else if(minhuman == sum && ans[p] >= ans[i]) {
					p = i;
				}
				
			}
			System.out.print((horse[p]));
			for(int i=1;i<8;i++) System.out.print(" " + horse[(p+i)%8]);
			System.out.println();
		}
	}
	public static void main(String[] args) {
		new Main().run();
	}
}
