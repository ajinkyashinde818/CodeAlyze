import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc =new Scanner(System.in);
    int K =sc.nextInt();
    int N =sc.nextInt();
    int A[] =new int[N];
    int B[] =new int[N];
    int C =0;int D=0;
    A[0]=sc.nextInt();
    for(int i=1;i<N;i++){
      A[i]=sc.nextInt();
      B[i]=A[i]-A[i-1];
      C =Math.max(C,B[i]);
      if(C==B[i]){D = i;}}
    B[0] =K-A[N-1]+A[0];
    C =Math.max(C,B[0]);
    if(C==B[0]){D=0;}
    long E =K-B[D];
    System.out.println(E);
  }
}
