import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int A[] = new int[N];
    int longest=0;
    for(int i=0;i<N;i++){
      A[i]=sc.nextInt();
    }
    for(int i=0;i<N-1;i++){
      if(longest<A[i+1]-A[i]){
        longest=A[i+1]-A[i];
      }
    }
    if((K-A[N-1])+A[0]>longest){
      longest=(K-A[N-1])+A[0];
    }
    System.out.println(K-longest);
  }
  

  
}
