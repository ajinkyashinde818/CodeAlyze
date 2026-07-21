import java.util.Scanner;

public class Main{
  static int A,B,K;
  static int C;
  static int[] D;
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int j=0;
    A = sc.nextInt();
    B = sc.nextInt();
    K = sc.nextInt();
    D = new int[110];
    C = gcm(A,B);
    for(int i=C;i>0;i--){
      if(C%i==0){
        D[j]=i;
        j++;
      }
    }
    System.out.println(D[K-1]);

  }

  static int gcm(int a,int b){
	if(a<b){
      return gcm(b,a);
    }
    else{
      if(b==0){
        return a;
      }
      else{
        return gcm(b,a%b);
      }
    }
  }

}
