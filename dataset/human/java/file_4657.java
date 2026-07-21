import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int m = sc.nextInt();
			int n = sc.nextInt();
			if(m==0 && n==0) break;
			
			int[] a = new int[n];
			int sum = 0;
			int max = 0;
			for(int i=0;i<n;i++){
				a[i] = sc.nextInt();
				sum += a[i];
				max = Math.max(max, a[i]);
			}
			max = Math.max(max, sum/m);
			
			int cnt = 0;
			for(int i=max;;i++){
				sum = 0;
				cnt = 0;
				for(int j=0;j<n;j++){
					sum+=a[j];
					if(sum>i){
						j--;
						cnt++;
						sum = 0;
					}
					if(cnt==m) break;
				}
				if(cnt<m){
					System.out.println(i);
					break;
				}
			}
		}	
	}	
}
