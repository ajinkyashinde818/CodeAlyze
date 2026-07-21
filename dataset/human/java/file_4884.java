import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long N = sc.nextLong();
    long answer =0;
    if(N%2==1){
      System.out.println(0);
      return;
    }
    long tmp = N/2;
    for(long i=1;i<30;i++){
      answer = answer + (long)tmp/(long)(Math.pow((long)5,i));
    }
    System.out.println(answer);
    
    
  }
  

  
}
