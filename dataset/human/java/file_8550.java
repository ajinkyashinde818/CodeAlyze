import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> values = new ArrayList<>();

        for (int i = 1; i <= 100; i++) {
            if (((a % i) == 0) && ((b % i) == 0)) {
                values.add(i);
            }
        }
        Collections.sort(values);
        Collections.reverse(values);

        System.out.println(values.get(k - 1));
    }

}
