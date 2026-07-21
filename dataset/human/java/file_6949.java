import java.util.*; 

class Main{
public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        int n=sc.nextInt();
  		int max=0;

  		int[] a=new int[n];
		for(int c=0;c<n;c++){
    		a[c]=sc.nextInt();
    	}
  		for(int d=0;d<n-1;d++){
        	if((a[d+1]-a[d])>max){
            	max=a[d+1]-a[d];
            }
        }
  
  		if((k-a[n-1]+a[0])>max){
        	max=k-a[n-1]+a[0];
        }
    
  int ans=k-max;
 	

    	System.out.println(ans);
    }
}
