import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Main m = new Main(sc);
        m.show(m.solve());
        sc.close();
    }
    
	//フィールド
    Scanner sc;
    int N;
    int R;
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        this.N = sc.nextInt();
        this.R = sc.nextInt();
    }
    
    //解答処理
    private int solve() {
        int rate = 0;
        
        if (N >= 10) {
        	rate = R;
        } else {
        	int K = N;
        	rate = R + (100 * (10-K));
        }
        
        return rate;
    }
    
    //出力
    public void show(int answer) {
        System.out.println(answer);
    }

}
