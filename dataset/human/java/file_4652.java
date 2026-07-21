import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            while(sc.hasNext()) {
                int m=sc.nextInt();
                int n=sc.nextInt();
                if(m+n==0) break;
                int[] book=new int[n+1];
                int max = 0;
                int sum = 0;
                for(int i=0; i<n; i++) {
                    book[i]=sc.nextInt();
                    if(max < book[i])
                    	max = book[i];
                    	sum += book[i];
                }
                
                int g=0;
                for(int i=max;i<=sum;i++) {
                	int h = m;
                	int[] each = new int[n+1];
	                int end = 0;
	                for(int j=0; j<n; j++) {
	                    	if(each[h]+book[j] >i && h==1) {
	                    		end = 1;
	                    		break;
	                    	}
	                    	if(each[h]+book[j] >i)h--;
	                    	each[h] += book[j];
	                    }
	                	g = i;
	                	if(end==0)break;
                }
                System.out.println(g);
            }
        }
    }
}
