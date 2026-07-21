import java.util.*;
import java.text.*;

public class Main {

    Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();
    int g = sc.nextInt();
    int[][] arr = new int[d][2];
    int res = (int)1e5;

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        for (int i=0; i<d; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }

        dfs("");

        System.out.println(res);

    }

    void dfs(String s) {
        if (s.length()==d) {
//            System.out.println(s);
            int sum = 0;
            int cnt = 0;
            for (int i=0; i<d; i++) {
                if (s.charAt(i)=='1') {
                    sum += arr[i][0] * 100 * (i+1) + arr[i][1];
                    cnt += arr[i][0];
                }
            }
            sum = g - sum;
//            System.out.println(sum);
            if (sum<=0) {
//                System.out.println(cnt);
                res = Math.min(res, cnt);
            } else {
                for (int i=d; 1<=i; i--) {
                    if (s.charAt(i-1)=='0') {
                        int max = arr[i-1][0]-1;
                        int need = sum%(100*i)==0 ? sum/(100*i) : (sum/(100*i))+1;
                        if (need<=max) {
                            cnt += need;
                            sum -= (100*i)*need;
                            if (sum<=0) break;
                        } else {
                            sum -= (100*i)*max;
                            cnt += max;
                            if (sum<=0) break;
                        }
                    }
                }
//                System.out.println(cnt);
                if (sum<=0) res = Math.min(res, cnt);
            }

        } else {
            for (int i=0; i<2; i++) {
                dfs(s + i);
            }
        }
    }

//    void dfs(String s) {
//        if (split(s, 'T')==d-1) {
//            System.out.println(s);
//            String[] ts = s.split("T", 0);
//            int[] a = new int[d];
//            int cnt = 0;
//            for (int i=0; i<d; i++) a[i] = Integer.parseInt(ts[i]);
//            int sum = 0;
//            for (int i=0; i<d; i++) {
//                cnt += a[i];
//                sum += a[i] * 100 * (i+1);
//                if (a[i]==arr[i][0]) sum += arr[i][1];
//            }
//            if (g<=sum) res = Math.min(res, cnt);
//        }
//        else {
//            for (int i=0; i<d; i++) {
//                for (int j=0; j<=arr[i][0]; j++) {
//                    dfs(s + j + "T");
//                }
//            }
//        }
//    }
//
//    int split(String s, char c) {
//        return s.split(c + "").length - 1;
//    }


}
