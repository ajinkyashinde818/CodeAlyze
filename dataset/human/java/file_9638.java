import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc =new Scanner(System.in);
    int N =sc.nextInt();
    int x =0;
    for(int i=0;i<N;i++){
      int D =sc.nextInt();
      int E =sc.nextInt();
      if(D==E){x=x+1;}
      else{x=0;}
      if(x==3){System.out.println("Yes");System.exit(0);}
    }
    System.out.println("No");
  }
}
