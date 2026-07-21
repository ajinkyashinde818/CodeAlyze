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
    char X;
    char Y;
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        this.X = sc.next().charAt(0);
        this.Y = sc.next().charAt(0);
    }
    
    //解答処理
    private char solve() {
    	//大小関係はアスキーコードと同じ
        char answer = '>';
        
        if (X == Y) {
        	answer = '=';
        } else if (X < Y) {
        	answer = '<';
        }
        
        return answer;
    }
    
    //出力
    public void show(char answer) {
        System.out.println(answer);
    }

}
