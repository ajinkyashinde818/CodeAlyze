import java.util.*;
public class Main{
  public static void main(String[] args){
  	Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();
    int[][] t = new int[d][2];
    for(int i=0;i<d;i++){
    	t[i][0] = sc.nextInt();
      	t[i][1] = sc.nextInt();
    }
    boolean flag = false;
    for(int i=0;i<d-2;i++){
    	if(t[i][0] == t[i][1] && t[i+1][0] == t[i+1][1] && t[i+2][0] == t[i+2][1]) flag = true;
    }
    if(flag) System.out.println("Yes");
    else System.out.println("No");
  }
}
