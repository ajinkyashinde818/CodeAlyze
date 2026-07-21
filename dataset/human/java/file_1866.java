import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int D = sc.nextInt();
        int G = sc.nextInt() / 100;

        int[] p = new int[D];
        int[] c = new int [D];

        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt() / 100;
        }

        int minQNum = 1000000;

        NEXT_PTN: for (int i = 0; i <= Math.pow(2, D) - 1; i++) {
            String binary = Integer.toBinaryString(i);
            String dlenZeros = "";
            for (int j = 0; j < D; j++) dlenZeros += "0";
            if (binary.length() < D) {
                binary = dlenZeros.substring(0, D - binary.length()).concat(binary);
            }

            int score = 0;
            int qnum = 0;

            for (int j = 0; j < D; j++) {
                if (binary.charAt(j) == '1') {
                    score += (j + 1) * p[j] + c[j];
                    qnum += p[j];
                }
            }

            if (score >= G) {
                if (qnum < minQNum) {
                    minQNum = qnum;
                }

                continue;
            }

            for (int j = D - 1; j >= 0; j--) {
                if (binary.charAt(j) == '1') {
                    continue;
                }

                int remain = G - score;
                if (remain > (j + 1) * (p[j] - 1)) {
                    continue NEXT_PTN;
                }

                int remainNum = (int) (Math.ceil(remain / (j + 1.0)));
                qnum += remainNum;
                break;
            }

            if (qnum < minQNum) minQNum = qnum;
        }

        System.out.println(minQNum);
    }
}
