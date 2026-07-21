import java.util.*;

public class Main {
	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		String a[] = new String[n];
		for(int i=0;i<n;i++) {
			a[i] = sc.next();
		}
		String b[] = new String[m];
		for(int i=0;i<m;i++) {
			b[i] = sc.next();
		}
		sc.close();
		
		for(int i=0;i<n;i++) {
			if(i+m-1>=n) break;
			int idx = -1;
			int now = 0;
			while(now<n) {
				idx = a[i].indexOf(b[0],now);
				if(idx == -1)break;
				now = idx+1;
				boolean ok = true;
				for(int j=1;j<m;j++) {
					if(!b[j].equals(a[i+j].substring(idx,idx+m))) {
						ok = false;
						break;
					}
				}
				if(ok) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}
