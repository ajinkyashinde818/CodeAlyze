import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		int minus = 0;
		int zero = 0;
		long[] absmin = new long[2];
		Arrays.fill(absmin,Integer.MAX_VALUE);
		for(int i = 0;i<n;i++){
			a[i] = sc.nextLong();
			if(a[i]<0)minus++;
			if(a[i]==0)zero++;
			if(Math.abs(a[i])<absmin[1]){
				absmin[1]=Math.abs(a[i]);
				absmin[0]=i;
			}
		}
		sc.close();
		long ans = 0;
		if(zero!=0 || minus%2==0){
			for(int i = 0;i<n;i++){
				ans += (long)Math.abs(a[i]);
			}
		}else{
			for(int i = 0;i<n;i++){
				if(i!=absmin[0])ans += (long)Math.abs(a[i]);
			}
          ans-=absmin[1];
		}
		System.out.println(ans);
	}
}
