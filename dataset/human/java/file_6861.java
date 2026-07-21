import java.util.*;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
    int k = Integer.parseInt(sc.next());
    int n = Integer.parseInt(sc.next());
    int[] a = new int[n];
    for(int i = 0 ; i < n ; i++){
      a[i] = Integer.parseInt(sc.next());
    }
      Arrays.sort(a);
  int max = 0;
    for(int i = 0 ; i < n ; i++){
      int meter = 0;
      if(i != n - 1)
      meter = Math.abs(a[i] - a[i + 1]);
        else
          meter = k - Math.abs(a[i] - a[0]);
      if(max < meter)
        max = meter;
    }
  System.out.println(k - max);
    }
      
      
      
}
