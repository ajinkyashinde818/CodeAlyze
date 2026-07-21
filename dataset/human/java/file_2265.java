import java.util.Scanner;
 
 
public class Main{
     
	
    public static void main(String[] args){
    	
    	final Scanner sc = new Scanner(System.in);
    	
    	final int N = sc.nextInt();
    	
    	int[] sum = new int[100003];
    	
    	for(int i = 0; i < N; i++){
    		final int a = sc.nextInt();
    		final int b = sc.nextInt();
    		
    		sum[0]++;
    		sum[a]--;
    		sum[b+1]++;
    	}
    	
    	for(int i = 1; i <= 100002; i++){
    		sum[i] += sum[i-1];
    	}
    	/*
    	for(int i = 2; i <= N + 1; i++){
    		System.out.print(sum[i] + " ");
    	}
    	System.out.println();
    	*/
    	int max = 0;
    	for(int i = 2; i <= N + 1; i++){
    		//System.out.print(sum[i] + " ");
    		//System.out.print((N + 1 - i) + " ");
    		if(sum[i] <= (N + 1 - i)){
    			max = Math.max(max, i - 1);
    		}
    	}
    	
    	System.out.println(max);
    }
     
}
