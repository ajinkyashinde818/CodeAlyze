import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
    int[][] dice = new int[N][2];
    for(int i = 0; i < N; i++){
      dice[i][0] = scan.nextInt();
      dice[i][1] = scan.nextInt();
    }
    
    int count = 0;
    String judge = "No";
    for(int[] roll: dice){
      if(roll[0] != roll[1]){
        count = 0;
      } else {
        count += 1;
      }
      
      if(count == 3){
        judge = "Yes";
        break;
      }
    }
    
    System.out.println(judge);	
  }
}
