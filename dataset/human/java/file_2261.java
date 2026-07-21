import java.util.Scanner;
public class Main {
	static int a,b;
	static int ans;
	
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 while(sc.hasNext()) {
			ans = 0;
			int n = sc.nextInt();
			int[] friend = new int[100011];
			for(int i=0;i<100011;i++) {
				friend[i] = 0;
			}
			while(n-->0){
				a = sc.nextInt();
				b = sc.nextInt();
				for(int i=a-1;i<b;i++) {
					friend[i]++;
				}
			}
			for(int i=0;i<=100001;i++) {
				if(i <= friend[i]) ans = i;
			}
			System.out.println(ans);
		 }	 
	}
}
