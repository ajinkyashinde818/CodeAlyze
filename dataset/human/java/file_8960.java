import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
	Scanner sc = new Scanner(System.in);

	String code(int t){
		int h = t/(60*60);
		t%=(60*60);
		int m = t/60;
		int s = t%60;
		
		String ret = "";
		if(h < 10){
			ret += "0";
		}
		ret += h;
		ret += ":";
		if(m < 10){
			ret += "0";
		}
		ret += m;
		ret += ":";
		if(s < 10){
			ret += "0";
		}
		ret += s;
		return ret;
		
	}
	void run() {
		for (;;) {
			int n = sc.nextInt();
			if (n == 0) {
				break;
			}

			int d[][] = new int[n][3];
			boolean z[][] = new boolean[n][60 * 60 * 12];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 3; j++) {
					d[i][j] = sc.nextInt();
				}
			}

			int t = 0;
			for (int h = 0; h < 12; h++) {
				for (int m = 0; m < 60; m++) {
					for (int s = 0; s < 60; s++) {
						int hd = h * 5 + m / 12;

						int hh[] = { 0, 0, 1, 1, 2, 2 };
						int mm[] = { 1, 2, 2, 0, 1, 0 };
						int ss[] = { 2, 1, 0, 2, 0, 1 };
						for (int i = 0; i < n; i++) {
							boolean ok = false;
							for (int j = 0; j < 6; j++) {
								if ((d[i][mm[j]] - d[i][hh[j]] + hd - m) % 60 == 0) {
									if ((d[i][ss[j]] - d[i][hh[j]] + hd - s) % 60 == 0) {
										ok = true;
									}
								}
							}
							if(ok){
//								System.out.println(i+" "+t);
								z[i][t] = true;
							}
						}
						t++;
					}
				}
			}

			int length = Integer.MAX_VALUE;
			
			int start = 0;
			int end = 0;
			
			int ansStart = 0;
			
			int count[] = new int[n];
			
			
			for(;end <= 60*60*12;){
				boolean ok = true;
				for(int i = 0; i < n ; i++){
					if( count[i] == 0){
						ok = false;
					}
				}
				if(ok){
					if(length > end - start -1 ){
						length = end - start-1;
						ansStart = start;
					}
				}
				
				if(ok){
					for(int i = 0; i < n ; i++){
						if(z[i][start]){
							count[i]--;
						}
					}
					start++;
					
					
				}else{
					if(end >= 60*60*12){
						break;
					}
					for(int i = 0; i < n ; i++){
						if(z[i][end]){
//							System.out.println(i+":"+end+"here");
							count[i]++;
						}
					}
					end++;
				}
			}
			
			System.out.println(code(ansStart )+" "+ code(ansStart+length));
		}

	}

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}
}
