import java.util.Scanner;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        // 入力データの取得
        Scanner scanner = new Scanner(System.in);
        StringBuilder inputStringData = new StringBuilder(scanner.nextLine());
        int repeatNum = scanner.nextInt();
        boolean reverseFlag = false;
        int frontCount = 0;
        int backCount = 0;
        ArrayList<String> addFrontList = new ArrayList<>();
        ArrayList<String> addBackList = new ArrayList<>();
        for (int count = 0; count < repeatNum; count++) {
            if (scanner.nextInt() == 1) {
                reverseFlag = !reverseFlag;
            } else {
                int judgmentNum = scanner.nextInt();
                if (!reverseFlag) {
                    if (judgmentNum == 1) {
                        addFrontList.add(scanner.next());
                        frontCount++;
                    } else {
                        addBackList.add(scanner.next());
                        backCount++;
                    }
                } else {
                    if (judgmentNum == 1) {
                        addBackList.add(scanner.next());
                        backCount++;
                    } else {
                        addFrontList.add(scanner.next());
                        frontCount++;
                    }
                }
            }
        }
        scanner.close();

        // 結果の処理
        StringBuilder displayStringBuilder = new StringBuilder();
        if (reverseFlag) {
            for (int index = backCount - 1; index >= 0; index--) {
                displayStringBuilder.append(addBackList.get(index));
            }
            displayStringBuilder.append(inputStringData.reverse().toString());
            for (int index = 0; index < addFrontList.size(); index++) {
                displayStringBuilder.append(addFrontList.get(index));
            }
        } else {
            for (int index = frontCount - 1; index >= 0; index--) {
                displayStringBuilder.append(addFrontList.get(index));
            }
            displayStringBuilder.append(inputStringData.toString());
            for (int index = 0; index < addBackList.size(); index++) {
                displayStringBuilder.append(addBackList.get(index));
            }
        }

        // 結果の出力
        System.out.println(displayStringBuilder.toString());

    }

}
