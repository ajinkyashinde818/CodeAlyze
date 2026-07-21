import java.util.Scanner;

class Main{
  public static void main(String[]args){
    
  Scanner sc=new Scanner(System.in);
   int N=sc.nextInt();
   int R=sc.nextInt();
   int X;
    
    if(N>=10){
      X=R;
      System.out.println(X);
    }else{
      X=R+100*(10-N);
      System.out.println(X);
    }
  }
}
