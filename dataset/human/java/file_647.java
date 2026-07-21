import java.io.*;
import java.util.*;
public class Main{
   
     public static void main(String []args){
       Scanner s=new Scanner(System.in);
       long n=s.nextLong();
       long r=s.nextLong();
       if(n>=10)
       System.out.println(r);
       else
       System.out.println(100*(10-n)+r);
     }}
