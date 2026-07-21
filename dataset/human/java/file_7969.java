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
        int a=s.nextInt(),b=s.nextInt();
       long x=(long)a*b;
       x/=gcd(a,b);
       
        out.write(x+"\n");
        out.flush();
  }
}
