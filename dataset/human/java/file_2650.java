import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main {

static long[] list=new long[87];

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

  // String nyuA=sc.nextLine();
 //  String nyuB=sc.nextLine();
 
   String[] s=sc.nextLine().split("");
     String[] t=sc.nextLine().split("");
Arrays.sort(s);
Arrays.sort(t);

String S="";
String T="";
for(String temp:s)S+=temp;
for(String temp:t)T=temp+T;

String[] so={S,T};
Arrays.sort(so);

//int N=Integer.parseInt(nyuA);

//int Y=Integer.parseInt(e[1]);
//int Z=Integer.parseInt(e[2]);

if(S.equals(T))
System.out.println("No");
else if(S.equals(so[0]))
System.out.println("Yes");
else
System.out.println("No");



}

}
