import java.util.*;
import java.util.Map.Entry;
 
class Main {
	 static int mod =  (int) (Math.pow(10,9)+7);
//	 static int mod = 998244353;
   public static void main(String[] args) {
	   
       Scanner sc = new Scanner(System.in);
       String S = sc.next();
       char[] c = S.toCharArray();
       
       int i=c.length-1;
       boolean flg=true;
       while(i>0) {
    	   if(c[i-2]=='s') {
    		   if(c[i]=='r' && c[i-1]=='e' && c[i-3]=='a' && c[i-4]=='r' && c[i-5]=='e') {
    			   i=i-6;
    		   } else {
    			   flg=false;
    			   break;
    		   }
    	   } else if(c[i]=='r') {
    		   if(c[i-1]=='e' && c[i-2]=='m' && c[i-3]=='a' && c[i-4]=='e' && c[i-5]=='r' &&  c[i-6]=='d') {
    			   i=i-7;
    		   } else {
    			   flg=false;
    			   break;
    		   }
		   } else if(c[i]=='e') {
    		   if(c[i-1]=='s' && c[i-2]=='a' && c[i-3]=='r' && c[i-4]=='e') {
    			   i=i-5;
    		   } else {
    			   flg=false;
    			   break;
    		   }
			   
		   } else if(c[i]=='m') {
    		   if(c[i-1]=='a' && c[i-2]=='e' && c[i-3]=='r' && c[i-4]=='d') {
    			   i=i-5;
    		   } else {
    			   flg=false;
    			   break;
    		   }
		   } else {
			   flg=false;
			   break;			   
		   }
    		   
    	   
       }
       String ans;
       if(flg==true) {
    	   ans="YES";
       } else {
    	   ans="NO";    	   
       }
	   System.out.println(ans);
   }
}
