import java.util.*;
 
public class Main {
  	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
        int distance = k - list.get(n-1) + list.get(0);
        for (int j = 2; j < n; j++) {
            if (distance < list.get(j) - list.get(j-1)) {
                distance = list.get(j) - list.get(j-1);
            }
        }
        System.out.println(k - distance);
    }
}
