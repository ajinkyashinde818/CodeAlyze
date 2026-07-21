import java.util.*;
 
public class Main{
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    String[] S = sc.nextLine().split(" ");
    int N = Integer.parseInt(S[0]);
    long K = Long.parseLong(S[1]);
    S = sc.nextLine().split(" ");
    
    int[] nums = new int[N];
    for(int i = 0; i < N; i++){
      nums[i] = Integer.parseInt(S[i]);
    }
    
    int ans = 1;
    int[] reached = new int[N];
    reached[0]++;
    boolean flag = true;
    int count = 0;
    while(K > 0){
      ans = nums[ans-1];
      K--;
      
      if(reached[ans-1] == 1){
        count++;
      }
      if(reached[ans-1] == 2 && flag){
        K %= count;
        flag = false;
      }
      reached[ans-1]++;
    }
    System.out.println(ans);
  }
}
