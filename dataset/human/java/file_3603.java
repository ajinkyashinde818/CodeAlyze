import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String X = scanner.next();
        String Y = scanner.next();
        String judge = "=";

        //listにA～Fを追加
        List<String> list = new ArrayList<>();
        for (String s : new String[] {"A", "B", "C", "D", "E", "F"}) {
            list.add(s);
        }

        int x = list.indexOf(X);
        int y = list.indexOf(Y);

        if (x < y) {
            judge = "<";
        } else if (x > y) {
            judge = ">";
        }
        System.out.println(judge);
    }

}
