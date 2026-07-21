import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        List<Integer> order = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            order.add(sc.nextInt());
        }

        List<Integer> satisfaction = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            satisfaction.add(sc.nextInt());
        }

        List<Integer> moreSatisfaction = new ArrayList<>();
        for (int i = 0; i < n-1; i++) {
            moreSatisfaction.add(sc.nextInt());
        }

        int sum = 0;
        int preOrder = 30;
        for (int i = 0; i < n; i++) {
            Integer nowOrder = order.get(i);

            sum += satisfaction.get(nowOrder - 1);

            if (nowOrder - preOrder == 1) {
                sum += moreSatisfaction.get(nowOrder - 2);
            }

            preOrder = nowOrder;
        }

        System.out.println(sum);

    }
}
