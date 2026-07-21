import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        List<Integer> house = new ArrayList<Integer>();
        for (int i=0; i<N; i++) {
            house.add(sc.nextInt());
        }
        int maxDistance = house.get(0) + K - house.get(N-1);
        for (int i=0; i<N-1; i++) {
            maxDistance = Math.max(maxDistance, house.get(i+1) - house.get(i));
        }
        System.out.println(K-maxDistance);
    }
}
