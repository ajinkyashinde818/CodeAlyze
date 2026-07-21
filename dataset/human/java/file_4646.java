import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	int solve(int m,int n,int a[]){
		int lb = 0,ub = 0;
		for(int i = 0;i < n;i++){
			ub = ub + a[i];
		}
		int mid = ub / m;
		while(true){
			int cnt = 0;
			for(int i = 0;i < m;i++){
				int num = 0;
				while(true){
					if(cnt == n)break;
					if(num + a[cnt] <= mid){
						num = num + a[cnt];
						cnt++;
					}else{
						break;
					}
				}
			}
			if(cnt == n){
				ub = mid;
				mid = (lb+ub)/2;
				if(ub - lb == 1)break;
			}else{
				lb = mid;
				mid = (lb+ub)/2;
				if(ub - lb == 1)break;
			}
		}
		return ub;
	}
	void doIt() { 
		while(true){
			int m = sc.nextInt();
			int n = sc.nextInt();
			if(n+m == 0)break;
			int book[] = new int [n];
			for(int i = 0;i < n;i++){
				book[i] = sc.nextInt();
			}
			System.out.println(solve(m,n,book));
		}
     }
    public static void main(String[] args) {
    	// TODO Auto-generated method stub
    	new Main().doIt();
    }
}
