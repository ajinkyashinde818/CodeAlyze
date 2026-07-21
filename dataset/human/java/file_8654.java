import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc =new Scanner(System.in);
    int A =sc.nextInt();
    int B =sc.nextInt();
    int K =sc.nextInt();
    int C =Math.min(A,B);
    int D[] =new int[K];
    int x =0;
    for(int i=C;i>0;i--){
      if(!(B%i==0)){continue;}
      if(!(A%i==0)){continue;}
      D[x]=i;
      x=x+1;
      if(x==K){break;}}
    System.out.println(D[K-1]);
  }
}
