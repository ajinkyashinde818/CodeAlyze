import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	void run(){
		for(;;){
			int m = sc.nextInt();
			int n = sc.nextInt();
			
			if((m|n) == 0){
				break;
			}
			
			
			int[] bs = new int[n];
			
			for(int i =0 ; i < n; i++){
				bs[i] = sc.nextInt();
			}
			
			
			int max = 1500000;
			int min = 0;
			for(;;){
//				System.out.println(max +" "+ min);
				if(max == min){
					break;
				}
				int t = (max+min)/2;
				
				boolean ok =true;
				
				int ind = 0;
				for(int i =0 ; i < m;i++){
					int cap = t;
					for(;ind < n && cap >= bs[ind]; ind++){
						cap -= bs[ind];
					}
				}
				ok = (ind == n);
				
				if(ok){
					max = t;
				}else{
					min = t+1;
				}
			}
			
			System.out.println(min);
		}
		
		
		
		
	}
	public static void main(String[] args){
		Main m = new Main();
		m.run();
	}
}
