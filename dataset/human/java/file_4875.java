import java.util.*;
import java.io.*;
import java.lang.*;
public class Main{
public static int gcd(int a,int b){
	if(b==0){return a;}
	return gcd(b,a%b);
}

public static void main(String[] args) throws FileNotFoundException, IOException{
       Scanner s=new Scanner(System.in);
       BufferedWriter out=new BufferedWriter(new OutputStreamWriter(System.out));
        long n=s.nextLong();
         if(n%2l==1){out.write(0+"\n");}
        else{
        	long res=n/10,tmp=50l;
        	while(tmp<=n&tmp>0){
        		res+=n/tmp;
        		tmp=(long)tmp*5;
        	}
        	out.write(res+"\n");
        }
      
        
        out.flush();
  }
}
