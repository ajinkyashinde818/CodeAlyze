import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();

        int[] c = new int[n];
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        boolean isAchievable = false;
        int minRefBooksPrice = -1;

        // ex:100(=4)
        int numPattern =  (int) Math.pow(2, n);
        // ex:1000(=8) due to set 1 prefix
        int flagnum =  numPattern * 2;

        // ex:1000(=8) to 1011(=11)
        for (int i = flagnum; i < flagnum+numPattern; i++) {
            String flag = Integer.toBinaryString(i);

            int [] curRikaido = new int[m];
            int curPrice = 0;
            //フラグに従い積み上げ
            for (int j = 0; j < n; j++) {
                if (flag.charAt(j+2)=='1') {
                    for (int j2 = 0; j2 < curRikaido.length; j2++) {
                        curRikaido[j2] += a[j][j2];
                    }
                    curPrice += c[j];
                }
            }
            //判定
            boolean isCurAchi = true;
            for (int j2 = 0; j2 < curRikaido.length; j2++) {
                if(curRikaido[j2]<x) {
                    isCurAchi = false;
                }
            }
            //値段更新
            if (isCurAchi) {
                if (minRefBooksPrice == -1) {
                    minRefBooksPrice =curPrice;
                }else if(minRefBooksPrice >curPrice) {
                    minRefBooksPrice =curPrice;
                }
            }
        }

        // 出力
        System.out.println(minRefBooksPrice);
    }
}
