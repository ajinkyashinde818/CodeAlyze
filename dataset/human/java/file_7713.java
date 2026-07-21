import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long k = sc.nextLong();
    int[] a = new int[n];
    LinkedHashSet<Integer> order = new LinkedHashSet<>();
    order.add(1);
    int tmp = 0;
    int ans = 0;
    int j = 0;
    boolean bool = true;

    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
    }

    while(bool){
      if(order.add(a[j])){
        order.add(a[j]);
        j = a[j] - 1;
      } else {
        tmp = a[j];
        bool = false;
      }
    }
    
    ArrayList<Integer> odr = new ArrayList<>(order);
    int index = odr.indexOf(tmp);
    int roop = odr.size() - index;

    if(k <= index){
      ans = odr.get((int)k);
    } else {
      ans = odr.get(index + (int)((k - index) % roop));
    }

    System.out.println(ans);

  }
}
