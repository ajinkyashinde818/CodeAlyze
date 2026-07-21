import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    TreeMap<Integer,Integer> start = new TreeMap<>();
    TreeMap<Integer,Integer> end = new TreeMap<>();
    for(int i = 0;i<m;i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      if(a == 1){
        start.put(b,1);
      }
      if(b == n){
        end.put(a,1);
      }
    }
    for(int i = 2;i<n;i++){
      if(start.containsKey(i) && end.containsKey(i)){
        System.out.println("POSSIBLE");
        return;
      }
    }
    System.out.println("IMPOSSIBLE");
  }
}
