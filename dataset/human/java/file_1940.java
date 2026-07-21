import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int d = in.nextInt();
		int g = in.nextInt();
		int[] p = new int[d];
		int[] c = new int[d];
		for(int i=0;i<d;i++) {
			p[i] = in.nextInt();
			c[i] = in.nextInt();
		}
		int[] pmax = new int[d];
		for(int i=0;i<d;i++) {
			pmax[i] = 100*(i+1)*p[i] + c[i];
		}
		
		int ans = Integer.MAX_VALUE;
		for(int i=0;i<(1<<d);i++) {
			int sump = 0;
			int sumpmax = 0;
			int highest = -1;
			int digit = 0;
			while(digit<d) {
				if(((i>>digit)&1)==1) {
					sump += p[digit];
					sumpmax += pmax[digit];
				}else {
					highest = digit;
				}
				digit++;
			}
			int plus = 0;
			while(sumpmax<g && plus<p[highest]-1) {
				plus++;
				sumpmax += 100*(highest+1);
			}
			if(sumpmax>=g) {
				ans = Math.min(ans, sump+plus);
			}
		}
		
		System.out.println(ans);
		
		
	}

}
