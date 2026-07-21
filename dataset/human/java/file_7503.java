import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        s = s.replaceAll("eraser", "0");
        s = s.replaceAll("erase", "0");
        s = s.replaceAll("dreamer", "0");
        s = s.replaceAll("dream", "0");
        s = s.replaceAll("0", "");
        if (s.length()== 0){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

    }

}
