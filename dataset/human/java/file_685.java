import java.util.*;

class Main
{
  public static void main(String args[]){
    Scanner s=new Scanner(System.in);
    int n=s.nextInt();
    int d=s.nextInt();
    if(n>=10)
      System.out.print(d);
    else 
      System.out.print(d+100*(10-n));
  }
}
