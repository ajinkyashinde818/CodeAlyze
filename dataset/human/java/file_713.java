import java.util.*;

public class Main {
	public static void main(final String[] args) {

        Scanner sc = new Scanner(System.in);

        // 参加回数
        int joinNum = sc.nextInt();
        // 表示レーティング
        int dispRating = sc.nextInt();

        // 内部レーティング判定
        if (joinNum >= 10) {

            System.out.println(dispRating);
        } else {

            System.out.println(dispRating + (100 * (10 - joinNum)));
        }
    }
}
