import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static List<String> list_ = new LinkedList<String>();

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        list_.add(scan.next());
        int totalQueryCount = Integer.parseInt(scan.next());

        boolean isReverse = false;
        for (int i = 0; i < totalQueryCount; i++) {
            int query1 = Integer.parseInt(scan.next());
            if (query1 == 1) {
                if (isReverse) {
                    isReverse = false;
                } else {
                    isReverse = true;
                }
            } else {
                int query2 = Integer.parseInt(scan.next());
                String query3 = scan.next();
                if (query2 == 1) {
                    t2f1(query3, isReverse);
                } else {
                    t2f2(query3, isReverse);
                }
            }
        }

        StringBuilder builder = new StringBuilder();
        for (String s : list_) {
            builder.append(s);
        }

        if (isReverse) {
            builder.reverse();
        }

        System.out.println(builder.toString());
        scan.close();
    }

    public static void t2f1(String input, boolean isReverse) {
        if (!isReverse) {
            list_.add(0, input);
        } else {
            list_.add(input);
        }
    }

    public static void t2f2(String input, boolean isReverse) {
        if (!isReverse) {
            list_.add(input);
        } else {
            list_.add(0, input);
        }
    }

}
