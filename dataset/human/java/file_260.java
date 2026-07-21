import java.util.*;
 
public class Main{

	public static void main(String []args){
	    Scanner sc= new Scanner(System.in);
	    
		int n=sc.nextInt();
		long total=0;
		long temp;
		long[] neg= new long[n];
		long smallest=0;
		int count=0;
		
		for(int i=0; i<n; i++){
		    temp=sc.nextLong();
		    
		    if(temp<0){
		        neg[count]=temp;
		        count++;
		        
		        
		    }
		    if(0>temp) temp=-1*temp;
		    if(i==0||smallest>temp) smallest=temp;
		    total=temp+total;
		}
		
		if(count%2==1){
		    total=total-smallest*2;
		
		}
		
		System.out.println(total);
	}
}
