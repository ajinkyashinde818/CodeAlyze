import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt(); // sankousyo
    int M = sc.nextInt(); // algori
    int X = sc.nextInt(); // 理解度
    int[] yen = new int[N]; // yen
    int[][] ji = new int[N][M]; // 実力
    for(int i=0; i<N ;i++){
      yen[i] = sc.nextInt(); 
      for(int j=0; j<M ;j++){
        ji[i][j] = sc.nextInt(); 
      }
    }
    int min = Integer.MAX_VALUE;
    for(int i = 0 ; i < Math.pow(2,N) ; i++) {
      int[] aa = new int[M];
      int sum = 0;
      for(int j = 0 ; j < N ; j++) {
        if((1 & (i>>j)) == 1) {
          sum += yen[j];
          for(int k =0; k<M ; k++){
            aa[k] += ji[j][k];
          }
        }
        boolean bf = true;
        for(int l =0; l<M ; l++){
          if(aa[l]<X){
            bf = false;
          }
        }
        if(bf==true){min = Math.min(min, sum);}
      }
    }
    if(min==Integer.MAX_VALUE){
      System.out.println(-1); 
    }else{
      System.out.println(min); 
    }
  }

}
