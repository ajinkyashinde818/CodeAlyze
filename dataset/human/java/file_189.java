import java.util.*;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		ArrayList<Integer>a = new ArrayList<>();
		int mc=0;
		int zc=0;
		int mmin = Integer.MAX_VALUE;
		int mi = -1;
		for(int i=0; i<n; i++) {
			int v=sc.nextInt();
			a.add(v);
			if(v<0) {
				mc++;
			}
			if(Math.abs(v)<mmin) {
				mmin = Math.abs(v);
				mi = i;
			}
			if(v==0) {
				zc++;
			}
		}
		long sum=0;

		for(int i=0; i<n; i++) {
			if((mc % 2 != 0 && zc == 0) && i == mi) {
				sum -= Math.abs(a.get(i));
			}else {
				sum += Math.abs(a.get(i));
			}
		}

		System.out.println(sum);
		sc.close();
	}

}
