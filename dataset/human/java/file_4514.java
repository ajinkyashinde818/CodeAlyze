import java.util.*;

public class Main{
 public static void main(String[] args){
    
    Scanner s=new Scanner(System.in);
    
    int A=s.nextInt();
    int B=s.nextInt();
    int C=s.nextInt();
    int m=0;
    
    if(A+B-C>=0)System.out.print(B+C);
    else{
     m=C-(B+A);
     System.out.print(B+C-m+1);
    }
  }
}
