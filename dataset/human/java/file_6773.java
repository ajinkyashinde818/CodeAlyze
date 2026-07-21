import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		
	 Scanner scan = new Scanner(System.in);
	 
	 int k = scan.nextInt(); 
	 int n = scan.nextInt();
	 int[] a = new int[n];
	 
	 for(int i = 0; i < n; i++ ) {
		 a[i] = scan.nextInt();
	 }
	 
	 int big = 0;
	 int first = 0;
	 int end = 0;
	 int tmp = 0;
	 int exc = 0;
	 int ans = 0;
	 int total = 0;
	 
	 for(int i = 0; i < n; i++) {
		 
		 
		 if(i < n - 1 ) {
			 tmp = a[i+1] - a[i];
			 total += tmp;
		 }
		 else if(i == n - 1) {
			 exc =  k - a[n-1] + a[0];
			 total += exc;
		 }
		 
		 
		 if(big < tmp ) {
			 big = tmp;
			 first = i;
			 end = i + 1;
		 }
		 if(big < exc ) {
			 big = exc;
			 first = 0;
			 end = n-1;
		 }
	 }
	 
	 if(first == 0) {
		 ans = a[end] - a[first];
	 }
	 else {
		 ans = k - a[end] + a[first];
	 }
	 
	 
	 System.out.println(total - big);
	 
	 
}
}
