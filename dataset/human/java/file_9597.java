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
    int[][] D;
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        this.N = sc.nextInt();
        this.D= new int[N][2];
        for (int i = 0; i < N; i++) {
        	for (int j = 0; j < 2; j++) {
        		this.D[i][j] = sc.nextInt();
        	}
        }
    }
    
    //解答処理
    private String solve() {
        String answer = "No";
        
        for (int i = 0; i < N-2; i++) {
        	if (D[i][0] == D[i][1] && D[i+1][0] == D[i+1][1] && D[i+2][0] == D[i+2][1]) {
        		answer = "Yes";
        		break;
        	}
        }
        
        return answer;
    }
    
    //出力
    public void show(String answer) {
        System.out.println(answer);
    }

}
