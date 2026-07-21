import java.util.*;
import java.io.*;

public class Main {
	static int a[], b[];
	
	public static void main(String[] args) throws IOException{
		//Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		a= new int[n];
		b= new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++){
			a[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++){
			b[i] = Integer.parseInt(st.nextToken());
		}
		
		int ans = 0;
		for(int i=29;i>=1;i--){
			int cntone = 0;
			int T = 1<<(i-1);
			
			for(int j=0;j<n;j++){
				b[j] = b[j]&(2*T-1);
			}
			for(int j=0;j<n;j++){
				a[j] = a[j]&(2*T-1);
			}
			Arrays.sort(a);
			Arrays.sort(b);
			int p1 = 0,p2=0, p3=0;
			for(int j=n-1;j>=0;j--){
				while(p1<n&& a[j]+b[p1]<T)	p1++;
				while(p2<n&& a[j]+b[p2]<2*T)	p2++;
				while(p3<n&& a[j]+b[p3]<3*T)	p3++;
				
				cntone += (p2-p1) + (n-p3);
				cntone &=1;
			}

			if(cntone %2 == 1)
				ans |= T;
		}
		System.out.println(ans);
	}
}
