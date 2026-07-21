import java.util.Scanner;

public class Main {
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] h = new int[n];
        for(int i = 0; i<n;i++) {
        	h[i] = sc.nextInt();
        }
        int[] d = new int[n];
        for(int i=0; i<n; i++){
            if(i==0){
                d[i] = h[i] + k - h[n-1];
            }else{
                d[i] = Math.abs(h[i]-h[i-1]);
            }
        }
        int sum=0;
        int mx=0;
        for(int i=0; i<n; i++){
            mx = Math.max(mx,d[i]);
        }
        int ans;
        ans = k - mx;  //总长减去两点间距离最短的那段
        
        
        System.out.print(ans);
        
	}
}
