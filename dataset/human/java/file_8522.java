import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int a = Integer.parseInt(s.next());
        int b = Integer.parseInt(s.next());
        int k = Integer.parseInt(s.next());

        int min = a < b ? a : b;
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0) {
                list.add(i);
            }
        }
        Optional<Integer> an = list.stream()
                .sorted(Comparator.reverseOrder())
                .skip(k - 1)
                .findFirst();

        System.out.println(an.orElse(0));
    }
}
