import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i<n; i++){
            list.add(sc.nextInt());
        }
        int distance = list.get(0) + k -list.get(n-1);
        for(int i = 1; i<n; i++){
            distance = Math.max(distance,list.get(i)-list.get(i-1));
        }
        System.out.println(k-distance);
    }
}
