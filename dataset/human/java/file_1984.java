import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.HashMap;

public class Main {

    public static void main(String[] args){
        new Main().solve();
    }
   void solve() {
	   Scanner sc=new Scanner(System.in);
	   int n=sc.nextInt();
	   int k=sc.nextInt();
	   long[]a=new long[n];
	   long[]b=new long[n];
	   for(int i=0;i<n;i++) {
		   a[i]=sc.nextLong();
		   b[i]=sc.nextLong();
	   }
	   long ans=0;
	   for(int i=0;i<=30;i++) {
		   long sum=0;
		   if(((k>>i)&1)==1) {
			   LOOP:for(int s=0;s<n;s++) {
				   if(((a[s]>>i)&1)==0) {
				   for(int j=i+1;j<=30;j++) {
					   if(((k>>j)&1)==0) {
						   if(((a[s]>>j)&1)==0) {
						   }else {
							  continue LOOP;
						   }
					   }else {
					   }
				   }
				   sum+=b[s];
				   }
			   }
		   }else {
			   continue;
		   }
		   
		   ans=Math.max(ans, sum);
	   }
	   
	   long sum1=0;
	   loop:for(int j=0;j<n;j++) {
		   for(int i=0;i<=30;i++) {
			   if(((k>>i)&1)==1) {
			   }else {
				   if(((a[j]>>i)&1)==1) {
					   continue loop;
				   }
			   }
		   }
		   sum1+=b[j];
	   }
	   ans=Math.max(ans, sum1);
	   
	   System.out.println(ans);
   }
}
