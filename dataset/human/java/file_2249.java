import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	Scanner sc = new Scanner(System.in);
	public void run(){
		int n = sc.nextInt();
		calc(n);
	}
	public void calc(int n){
		int[] memo = new int[100001];
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			for(int j = a-1; j < b; j++){
				memo[j] += 1;
			}
		}
		
		int max = 0;
		for(int i = 0; i < 100001; i++){
			int d = memo[i];
			if(d > max){
				if(d >= i) {
					d = i;
					max = d;
				}
			}
		}
		
		System.out.println(max);
	}
	
	public static void main(String[] args){
		new Main().run();
	}
	
}
