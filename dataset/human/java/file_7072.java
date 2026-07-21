import java.util.*;
import java.io.*;
import java.math.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++){
            list.add(sc.nextInt());
        }
        Collections.sort(list);
        int ans = list.get(n-1)-list.get(0);
        for(int i = 1; i < n; i++){
            ans = Math.min(ans, k-(list.get(i) - list.get(i-1)));
        }
        System.out.println(ans);
    }

}
