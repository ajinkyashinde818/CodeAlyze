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
    int K;
    int S;
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        K = sc.nextInt();
        S = sc.nextInt();
    }
    
    //解答処理
    private int solve() {
        int count = 0;
        
        for (int x=0; x<=K; x++){
        	for (int y=0; y<=K; y++) {
        		int z = S - x - y;
        		if (0<=z && z<=K && x+y+z == S) {
        			count++;
        		}
        	}
        }
        
        return count;
    }
    
    //出力
    public void show(int answer) {
        System.out.println(answer);
    }
}
