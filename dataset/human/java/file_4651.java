import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
        	while(true) {
        		int m = sc.nextInt();
        		int n = sc.nextInt();
        		if(m==0 && n==0) break;
        		int w [] = new int[n];
        		int sum = 0;
        		int max = 0;
        		for(int i=0;i<n;i++) {
        			w[i] = sc.nextInt();
        			sum += w[i];
        			max = Math.max(w[i], max);
        		}
        		max = Math.max(max, sum/m);
        		
        		for(int i=max;;i++) {
        			sum = 0;
        			int count = 0;
        			for(int j=0;j<n;j++) {
        				sum += w[j];
        				if(sum>i) {
        					j--;
        					count++;
        					sum = 0;
        				}
        				if(count==m) break;
        			}
        			if(count<m) {
        			System.out.println(i);
        			break;
        			}
        		}
        	}	
        }
    }
}
