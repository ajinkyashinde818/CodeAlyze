import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    Map<Integer, List<Integer>> map = new HashMap<>();
    for(int i = 0; i < m; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      if(!map.containsKey(a)){
        map.put(a, new ArrayList<Integer>());
      }
      if(!map.containsKey(b)){
        map.put(b, new ArrayList<Integer>());
      }
      List<Integer> list = map.get(a);
      list.add(b);
      map.put(a, list);
      list = map.get(b);
      list.add(a);
      map.put(b, list);
    }
    List<Integer> list = map.get(1);
    for(int i : list){
      List tmp = map.get(i);
      if(tmp.contains(n)){
        System.out.println("POSSIBLE");
        System.exit(0);
      }
    }
    System.out.println("IMPOSSIBLE");
  }
}
