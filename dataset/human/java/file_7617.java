import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    int MOD = (int)1e9 + 7;

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        int n = sc.nextInt();
        long m = sc.nextLong();
        int[] arr = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt() - 1;
        }

        boolean[] flag = new boolean[n];
        flag[0] = true;


        int pre = 0;
        int cle = 1;

        List<Integer> list = new ArrayList<>();
        list.add(0);

        int idx = 0;
        while (true) {
           int next = arr[idx];
            if (flag[next]) break;
            flag[next] = true;
            list.add(next);
            idx = next;
        }

//        System.out.println(arr[idx]);

//        for (int i=0; i<n; i++) System.out.println(flag[i]);

//        System.out.println(list);

        pre = list.indexOf(arr[idx]);
        cle = list.size() - pre;

//        System.out.println(cle);

        if (m < pre) {
            System.out.println(list.get((int)m) + 1);
        } else {
            long rem = (m - pre) % cle;
            System.out.println(list.get(pre+(int) rem) + 1);

        }


    }

}
