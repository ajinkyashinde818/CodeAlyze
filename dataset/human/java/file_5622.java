import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    int K=sc.nextInt();
    long S=sc.nextLong();
    long[] answer=new long[N];
    
    if(S==1000000000){
      for(int i=0;i<K;i++){
        answer[i]=1000000000;
      }
      for(int i=K;i<N;i++){
        answer[i]=1;
      }
    }else{
      for(int i=0;i<K;i++){
        answer[i]=S;
      }
      for(int i=K;i<N;i++){
        answer[i]=1000000000;
      }
    }
    for(int i = 0;i < answer.length;i++){
		if(i > 0)System.out.print(" ");
		System.out.print(answer[i]);
	}
  }
}
