import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}


	public void run() {
		Scanner sc = new Scanner(System.in);
		int d=sc.nextInt();
		int g=sc.nextInt();
		int p[]=new int[d];
		int c[]=new int[d];
		for(int i=0; i<d; i++) {
			p[i]=sc.nextInt();
			c[i]=sc.nextInt();
		}
		int ans = Integer.MAX_VALUE;
		for(int i=0; i<(1<<d); i++) {
			int s=0;
			int rest=-1;
			int cnt=0;
			for(int j=0; j<d; j++) {
				if(((i>>j)&1)==1) {
					s += (j+1)*100*p[j]+c[j];
					cnt += p[j];
				}else {
					rest=j;
				}
			}
			if(s<g) {
				int s1 = 100 * (rest+1);
				int need = (g-s+s1-1)/s1;
				if(need>=p[rest]) continue;
				cnt += need;
			}
			ans = Math.min(ans, cnt);
		}
		System.out.println(ans);
		sc.close();
	}


}
