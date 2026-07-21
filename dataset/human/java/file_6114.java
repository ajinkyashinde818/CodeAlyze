import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();

        int res = 0;// 条件を満たすx,y,zの値の組み合わせ数
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                int z = s - (x + y);
                if (z < 0 || z > k) continue;// zが範囲外のため次のループへ

                res++;
            }
        }

        System.out.println(res);
    }


}
