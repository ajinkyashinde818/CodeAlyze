import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int k = scan.nextInt();
    int s = scan.nextInt();
    long sum = 0;
    int check = s-2*k;
    int initial = (int) Math.max(0,check);

    for (int i=initial;i<=k;i++){
      int current = s-i;
      int start = 0;
      int end = k;
      if (current > 2*k){
        continue;
      }
      else if (current > k){
        start = current-k;
        sum += end-start+1;
      }
      else if (current >= 0){
        end = current;
        sum += end-start+1;
      }
    }
    System.out.println(sum);

  }

}
