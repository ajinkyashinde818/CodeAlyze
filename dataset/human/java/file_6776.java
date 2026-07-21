import java.util.*;

public class  Main{
	public static void main(String args[]){
	    Scanner sc = new Scanner(System.in);
	    int k = sc.nextInt();
      	int n = sc.nextInt();
      	int tmp=0,x1=sc.nextInt(),x=x1,y=sc.nextInt();
      	int max = y-x;
      
      	for(int i=0;i<n-2;i++){
        	x = y;
          	y = sc.nextInt();
          	tmp = y-x;
        	if(tmp>max) max = tmp;
      	}
      
		tmp = k+x1-y;
      	if(tmp>max) max = tmp;

      	System.out.println(k-max);
	}
}
