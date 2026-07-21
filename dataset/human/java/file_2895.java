import java.io.*;
import java.util.StringTokenizer;

class FlyingJenny {
	int a[] = {4,1,4,1,2,1,2,1};
	int b[] = {0,0,0,0,0,0,0,0};
	int c[] = {0,0,0,0,0,0,0,0};
	int ans[] = {-1,0,0,0,0,0,0,0};
	int s;

	FlyingJenny(String d) {
		s = 0;
		StringTokenizer st = new StringTokenizer(d);
		for (int i=0;i<8;i++) {
			b[i] = Integer.parseInt(st.nextToken());
			s += b[i];
		}
	}

	void Solve() {
		int sum = s;
		for (int i=0;i<8;i++) {
			int dif;
			int m = 0;
			for (int j=0;j<8;j++) {
				c[j] = a[(i+j)%8]; 
				dif = c[j]-b[j];
				if (dif<0) m -= dif;
			}
			if (m<sum) {
				sum = m;
				for (int j=0;j<8;j++) ans[j] = c[j];
			} else if (m==sum) {
				if (ans[0]==-1||Compare(c,ans)) {
					for (int j=0;j<8;j++) ans[j] = c[j];
				}
			}
		}
		boolean First = true;
		for (int i=0;i<8;i++) {
			if (First) {
				First = false;
				System.out.print(ans[i]);
			}
			else System.out.print(" "+ans[i]);
		}
		System.out.println("");
	}

	boolean Compare(int a1[],int a2[]) {
		for (int i=0;i<8;i++) {
			if (a1[i]==a2[i]) continue;
			else if (a1[i]<a2[i]) return true;
			else if (a1[i]>a2[i]) return false;
		}
		return true;
	}
}

class Main {
	public static void main(String args[]) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String buf;

		try {
			while ((buf = br.readLine())!=null) {
				FlyingJenny f = new FlyingJenny(buf);
				f.Solve();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
