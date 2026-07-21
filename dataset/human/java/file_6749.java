import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.run();
    }
    
    // 変数一覧
    long k;
    long n;
    ArrayList<Long> a = new ArrayList<Long>();

    public void run() {
        // 入力情報取得
        Scanner sc = new Scanner(System.in);
        k = sc.nextLong();
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong());
        }
        sc.close();

        // 解答処理
        solve();
    }
    
    private void solve() {
        ArrayList<Long> res = new ArrayList<Long>();
        for (int i = 1; i <= a.size(); i++) {
            if (i == a.size()) {
                res.add((k - a.get(a.size() - 1)) + a.get(0));
            } else {
                res.add(a.get(i) - a.get(i-1));
            }
        }
        res.sort(Comparator.reverseOrder());
        System.out.println(k-res.get(0));
    }
}
