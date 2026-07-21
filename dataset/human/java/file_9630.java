import java.util.*;
public class Main {
  public static void main (String[] args){
	Scanner sc = new Scanner(System.in);
    boolean result = false;
    int trial_num = sc.nextInt();
    int[][] combi = new int[trial_num][2];
    for(int i = 0; i < trial_num; i++) {
		for(int j = 0; j < 2; j++){
        	combi[i][j] = sc.nextInt();
        }
    }
    for(int i = 0; i < trial_num - 2; i++) {
        if(combi[i][0] == combi[i][1] 
           && combi[i+1][0] == combi[i+1][1] && combi[i+2][0] == combi[i+2][1])
     		result = true;
    }
    if(result) System.out.println("Yes");
    else System.out.println("No");
  }
}
