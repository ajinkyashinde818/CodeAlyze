import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] A = new int[N];
        for (int i=0;i<N;i++) {
            A[i] = sc.nextInt()-1;
        }

        int index = 0;
        int double_num = -1;
        int[] nums = new int[N];
        ArrayList<Integer> list = new ArrayList<Integer>();
        nums[index]++;
        list.add(index);
        while (true) {
            index = A[index];
            if (nums[index] == 1) {
                double_num = index;
                break;
            }
            nums[index]++;
            list.add(index);
        }

        ArrayList<Integer> before = new ArrayList<Integer>();
        ArrayList<Integer> after = new ArrayList<Integer>();
        boolean flag = false;
        int bound = -1;
        for (int i=0;i<list.size();i++) {
            if (list.get(i) == double_num) {
                bound = i;
                flag = true;
            }

            if (!flag) before.add(list.get(i));
            else after.add(list.get(i));
        }

        int ans = -1;
        if (K<bound) ans = before.get((int)K);
        else ans = after.get((int)((K-bound)%after.size()));
        System.out.println(ans+1);
    }
}
