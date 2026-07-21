import java.util.Scanner;

public class Main{
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        for (int i = 0; i < num; i++) {
            String[] str = new String[2];
            int[] ans = new int[2];
            for (int j = 0; j < 2; j++) {
                ans[j] = 0;
                str[j] = scan.next();
                for (int k = 0; k < str[j].length(); k = k + 2) {
                    String hoge = String.valueOf(str[j].charAt(k));
                    try {
                        String huga = String.valueOf(str[j].charAt(k + 1));
                        ans[j] = ans[j] + Integer.parseInt(hoge) * changeChar(huga);
                    } catch (Exception e) {
                        ans[j] = ans[j] + changeChar(hoge);
                        k--;
                    }
                }
            }
//            System.out.println((ans[0] + ans[1]));
            System.out.println(returnChar(ans[0] + ans[1]));

        }
    }

    public static String returnChar(int n) {
        String str = "";
        int data = 1000;
        while (true) {
            if (n / data >= 1) {
                if (n / data >= 2) {
                    str = str + n / data;
                }
                if (data == 1000) {
                    str = str + "m";
                }
                if (data == 100) {
                    str = str + "c";
                }
                if (data == 10) {
                    str = str + "x";
                }
                if (data == 1) {
                    str = str + "i";
                }
                n = n - (n / data) * data;
            }
            if (data == 1) {
                break;
            }
            data = data / 10;
        }
        return str;
    }

    public static int changeChar(String str) {
        if (str.equals("m")) {
            return 1000;
        }
        if (str.equals("c")) {
            return 100;
        }
        if (str.equals("x")) {
            return 10;
        }
        return 1;

    }
}
