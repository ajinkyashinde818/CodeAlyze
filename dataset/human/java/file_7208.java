import java.util.*;

public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();
        int n = sc.nextInt();

        List<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }

        Collections.sort(list);

        List<Integer> list2 = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                list2.add(list.get(0) + k - list.get(i));
            } else {
                list2.add(list.get(i + 1) - list.get(i));
            }
        }

        Collections.sort(list2);

         System.out.println(k - list2.get(n - 1));

        sc.close();
    }

}
