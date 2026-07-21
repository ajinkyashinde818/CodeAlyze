import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        int m;
        int x;

        n = sc.nextInt();
        m = sc.nextInt();
        x = sc.nextInt();
        Book[] books = new Book[n];
        int[] skill = new int[m];

        for (int i = 0; i < n; i++) {
            int cost = sc.nextInt();

            for (int j = 0; j < m; j++) {
                skill[j] = sc.nextInt();
            }
            books[i] = new Book(cost, skill);
        }
        
        System.out.println(solve(books, m, x));
    }
    
    /**
     * 全てのアルゴリズムスキルがx以上となるような最適な本の選択を行った場合の最小金額を返します。
     * @param books 本の種類
     * @param x 目標値
     * @return 全てのアルゴリズムが目標値以上となるような最低金額     
     */
    private static int solve(Book[] books, int m, int x) {
        int bit = books.length;
        int max = 1 << (bit + 1);
        int[] bitSet = {
            1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4056
        };

        int minCost = 1 << 30;
        for (int selectBit = 1; selectBit < max; selectBit++) {
            int[] skill = new int[m];
            int cost = 0;

            for (int i = 0; i < bit; i++) {
                if ((selectBit & bitSet[i]) != 0) {
                    cost += books[i].price;
                    for (int s = 0; s < m; s++) {
                        skill[s] += books[i].skill[s];
                    }
                }
            }
            
            boolean ok = true;
            for (int s = 0; s < m; s++) {
                if (skill[s] < x) {
                    ok = false;
                    break;
                }
            }
            
            if (ok && cost < minCost ) {
                minCost = cost;
            }
        }
        
        return minCost == (1 << 30) ? -1 : minCost;
    }
}

/**
 * 本を表すクラス。
 */
class Book {
    /** 値段 */
    int price;
    /** 各スキルアップ値 */
    int[] skill;
    
    public Book(int price, int[] skill) {
        this.price = price;
        this.skill = new int[skill.length];
        
        for (int i = 0; i < skill.length; i++) {
            this.skill[i] = skill[i];
        }
    }
}
