import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int val1 = sc.nextInt();
        int val2 = sc.nextInt();
        int val3 = sc.nextInt();

        List<Integer> k = new ArrayList<>();
        int loop = val1 > val2 ? val1 : val2;
        for (int i = 1; i <= loop; i++) {
            if ((val1 % i == 0) && (val2 % i == 0)) {
                k.add(i);
            }
        }
        Collections.sort(k);
        System.out.println(k.get((k.size() - 1) - (val3 - 1)));
    }
}
