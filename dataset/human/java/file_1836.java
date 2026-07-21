import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int D = sc.nextInt();
        int G = sc.nextInt();

        int[] p = new int[D];
        int[] c = new int[D];

        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int ans = Integer.MAX_VALUE;
        for (int mask = 0; mask < (1 << D); mask++) {//D桁の2進数全探索
            int sum = 0, num = 0, restMax = -1;
            for (int i = 0; i < D; i++) {
                if (((mask >> i) & 1) == 1) {
                    // ビットが立っていたら全て解く
                    sum += 100 * (i + 1) * p[i] + c[i];
                    num += p[i];
                } else {
                    // ビットが立っていなかったら中途半端に解いている。
                    // 解くべき問題は一番高い点数の問題(=一番でかい0の桁)
                    restMax = i;
                }
            }

            //　全て解く問題だけでは不十分
            if (sum < G && restMax != -1) {
                // 中途半端に解くと決めた問題の一問あたりの点数
                int point = 100 * (restMax + 1);
                //　必要な問題数
                int rest = (G - sum);
                int need = (rest + (point - 1)) / point;
                if (need >= p[restMax]) {
                    // 問題数が足りない,または全解きは除く
                    continue;
                }
                num += need;
            }
            ans = Math.min(ans, num);
        }

        System.out.println(ans);
    }
}
