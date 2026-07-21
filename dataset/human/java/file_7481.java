import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Main instance = new Main();
        instance.solve();
    }

    private void solve() {

        String s = sc.next();

        s = s.replace("eraser","1");
        s = s.replace("erase","1");
        s = s.replace("dreamer","1");
        s = s.replace("dream","1");
        s = s.replace("1","");
        System.out.println(s.equals("") ? "YES":"NO");
    }
}
