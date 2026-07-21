import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.next());
        Integer[] ary_1 = new Integer[n];
        Integer[] ary_2 = new Integer[n];
        Integer[] ary_3 = new Integer[n-1];

        for(int i = 0; i < n; ++i) {
            int tmp = sc.nextInt();
            ary_1[i] = tmp;
        }
        for(int i = 0; i < n; ++i) {
            int tmp = sc.nextInt();
            ary_2[i] = tmp;
        }
        for(int i = 0; i < n-1; ++i) {
            int tmp = sc.nextInt();
            ary_3[i] = tmp;
        }

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += ary_2[i];
        }

        //System.out.println(sum);

        for(int i = 0; i < n-1; ++i) {
            if(ary_1[i] + 1 == ary_1[i + 1]) {
                sum += ary_3[ary_1[i]-1];
            }
        }

        System.out.println(sum);
    }
}
