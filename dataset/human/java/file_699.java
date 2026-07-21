import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        int innerRating = 0;
        int joinNum = 0;
        int displayRating = 0;

        Scanner scanner = new Scanner(System.in);
        String inputData = scanner.nextLine();
        scanner.close();

        String[] editData = inputData.split(" ");

        joinNum = Integer.parseInt(editData[0]);
        displayRating = Integer.parseInt(editData[1]);

        if (joinNum <= 9) {
            innerRating = displayRating + (10 - joinNum) * 100;
        } else {
            innerRating = displayRating;
        }

        System.out.println(innerRating);

    }
}
