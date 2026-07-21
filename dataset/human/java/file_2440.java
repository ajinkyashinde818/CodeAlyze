import java.util.Scanner;
 
class Main {
    void solve() {
        Scanner in = new Scanner(System.in);
        String string = in.nextLine();
        System.out.println(string.substring(0,string.length() - 8));
    }
 
    public static void main(String[] args) {
        new Main().solve();
    }
}
