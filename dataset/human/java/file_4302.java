import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
      //System.out.println("Nの値が入力されました");
    int sum=0;
    int [][] A = new int [3][N];//配列の宣言

    for(int j=0;j<2;j++){//横の配列
      for(int i=0;i<N;i++){//縦の配列
      A[j][i] = scan.nextInt();
            }
    }
    for(int i=0;i<N-1;i++){
    A[2][i]=scan.nextInt();//Ciの入力
    }
    for(int i=0; i<N;i++){
      //System.out.print(A[1][i] );
      sum +=A[1][i];
      //if(A[0][i]==(A[0][i+1]+1)){
         //sum +=A[2][i];
      }
      for(int i=0;i<N-1;i++){
        if((A[0][i]+1)==A[0][i+1]){
        sum +=A[2][A[0][i]-1];
      }
    }

    System.out.println(sum);
  }
}
