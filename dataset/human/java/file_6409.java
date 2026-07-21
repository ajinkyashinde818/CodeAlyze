import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int S = sc.nextInt();
    int answer=0;
    for(int i=0;i<=K;i++){
      if(i>S){
        break;
      }
      for(int j=0;j<=K;j++){
        if(i+j>S){
          break;
        }
        if(S-i-j>=0&&S-i-j<=K){
            answer++;
        }
      }
    }
    System.out.println(answer);
  }
  

  
}
