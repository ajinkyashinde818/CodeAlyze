import java.util.Scanner;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] pl = new int[n];
    for(int i = 0; i < n; i++){
      pl[i] = Integer.parseInt(sc.next());
    }
    int max = 0;
    int cur = 0;
    for(int i = 0; i < n - 1; i++){
      max = Math.max(max, pl[i + 1] - pl[i]);
      if(max == pl[i + 1] - pl[i]){
        cur = i;
        
      }
    }
    max = Math.max((pl[0] + k) - pl[n - 1], max);
    if(max == pl[0] + k - pl[n - 1]){
      System.out.println(pl[n - 1] - pl[0]);
    }else{
      System.out.println(pl[cur] + k - pl[cur + 1]);
    }
  }
}
