import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
   public static void main(String[] args) {
	   
       Scanner sc = new Scanner(System.in);
       int N = sc.nextInt();
       int M = sc.nextInt();

       String s = new String();
       char[][] a = new char[(int)N][N];
       for (int i=0 ; i<N; i++) {
           s = sc.next();
           a[i]=s.toCharArray();
       }
       char[][] b = new char[(int)M][M];
       for (int i=0 ; i<M; i++) {
           s = sc.next();
           b[i]=s.toCharArray();
       }
       boolean flg=false;
       for(int i=0;i<N-M+1;i++) {
    	   for(int j=0;j<N-M+1;j++) {
    		   flg=false;
    		   for(int k=0;k<M;k++) {
    			   for(int l=0;l<M;l++) {
    				   if(a[i+k][j+l]!=b[k][l]) {
    					   flg=true;
    					   break;
    				   }
    			   }
    			   if(flg==true)break;
    		   }
    		   if(flg==false)break;
    	   }
    	   if(flg==false)break;
       }
       
       String ans=new String("No");
       if(flg==false) {
    	  ans="Yes";
       }
       
       System.out.println(ans);
   }
      

}
