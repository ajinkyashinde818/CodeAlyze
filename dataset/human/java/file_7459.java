import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        String[] strList = {"eraser", "erase", "dreamer", "dream"};
        for (String str : strList) {
            S = S.replace(str, "");
            if (S.isEmpty()) {
                System.out.print("YES");
                return;
            }
        }

        System.out.print("NO");

//        Scanner sc = new Scanner(System.in);
//        String S = sc.next();
//
//        S = S.replaceAll("eraser", "-");
//        S = S.replaceAll("erase", "-");
//        S = S.replaceAll("dreamer", "-");
//        S = S.replaceAll("dream", "-");
//        S = S.replaceAll("-", "");
//        if (S.length() == 0)
//            System.out.println("YES");
//        else
//            System.out.println("NO");
    }
}
