import java.util.Scanner;

public class Main {
    static int[][] learn;
    static int[] price;
    static int minCost = 1000000000;
    static int bookNum;
    static int algNum;
    static int minLearn;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        bookNum = scan.nextInt();
        algNum = scan.nextInt();
        minLearn = scan.nextInt();
        price = new int[bookNum];
        learn = new int[bookNum][algNum];
        for (int i = 0; i < bookNum; i++) {
            price[i] = scan.nextInt();
            for (int j = 0; j < algNum; j++) {
                learn[i][j] = scan.nextInt();
            }
        }
        getPrice(0, new int[algNum], 0);
        if (minCost == 1000000000){
            System.out.println(-1);
        }else{
            System.out.println(minCost);
        }
    }

    static void getPrice(int book, int[] nowLearn, int priceNow) {
        if (priceNow + price[book] < minCost) {
            int[] newLearn = new int[algNum];
            boolean done = true;
            for (int i = 0; i < algNum; i++) {
                newLearn[i] = nowLearn[i] + learn[book][i];
                if (newLearn[i] < minLearn) {
                    done = false;
                }
            }
            if (done) {
                minCost = Math.min(minCost, priceNow + price[book]);
            } else if (book < bookNum - 1) {
                getPrice(book + 1, newLearn, priceNow + price[book]);
            }
        }
        if (book < bookNum - 1) {
            getPrice(book + 1, nowLearn, priceNow);
        }
    }
}
