import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int n = sc.nextInt();
    int[][] d = new int[n][2];
    for(int i=0; i<n; i++){
      d[i][0] = sc.nextInt();
      d[i][1] = sc.nextInt();
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
      if(cnt>=3)  break;
      if(d[i][0]==d[i][1])  cnt++;
      else  cnt = 0;
    }
    
    if(cnt>=3){
      System.out.println("Yes");
    }
    else{
      System.out.println("No");
    }
  }
}
