import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int g = sc.nextInt();
		int p[] = new int[d];
		int c[] = new int[d];
		for (int i=0;i<d;i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		System.out.println(result(d,g,p,c));

	}

	private static int result(int d, int g, int[] p, int[] c) {
		int ans = Integer.MAX_VALUE;
		
		for (int i = 0; i<1<<d;i++) {
			int maxj = 0;
			int count = 0;
			int score = 0;
			for (int j=0;j<d;j++)
				if ((i>>j)%2==1) {
					count+=p[j];
					score += (j+1)*100*p[j] + c[j];
				} else
					maxj = j;
			if (score<g) {
				int t = (g-score+(maxj+1)*100-1)/((maxj+1)*100);
				if (t>=p[maxj]) {
					continue;
				}
				count +=t;
			}
			if (ans>count) ans=count;
		}
		
		return ans;
	}



}
