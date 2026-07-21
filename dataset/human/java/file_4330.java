import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();      
		int o=0;
      	int[] a=new int[n];
        PriorityQueue<Integer> num=new PriorityQueue<>();
        for(int i=0;i<n;i++){
        	a[i]=sc.nextInt();
            if(i>0 && a[i]==a[i-1]+1){
            	num.add(a[i-1]-1);
            }
         }
         for(int i=0;i<n;i++){
            int b=sc.nextInt();
        	o+=b;
         }
      //System.out.println(num);
         for(int i=0;i<n-1;i++){
            int c=sc.nextInt();
            
            if(num.peek()!=null && i==num.peek()){
        		o+=c;
                num.poll();
            }
         }
      	System.out.println(o);
    }  
 
}
