import java.util.Scanner;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();
    int C = Math.min(A,B);
    int count = 0;
    
    for(int i=1;i<=C;i++){
      if(A%i==0 && B%i==0){
        count++;
      }
    }
    int[] line = new int[count];
    int cc = 0;
    for(int j=1;j<=C;j++){
      if(A%j==0 && B%j==0){
        line[cc] = j;
        cc++;
      }
    }
   System.out.println(line[line.length-K]);
  }
}
