import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long A[] = new long[N];
    boolean isMinusCntIsOdd =false;
    long answer =0;
    for(int i=0;i<N;i++){
      A[i] = sc.nextLong();
      if(A[i]<0){
        isMinusCntIsOdd=!isMinusCntIsOdd;
        A[i]=(-1)*A[i];
      }
      answer = answer +A[i];
    }
    Arrays.sort(A);
    if(!isMinusCntIsOdd){
      System.out.println(answer);
      return;
    }else{
      answer = answer - A[0]*2;
      System.out.println(answer);
      return;
    }
    
      
      
  }
  

  
}
