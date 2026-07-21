import java.math.BigDecimal;
import java.util.*;

public class Main {
    public static void main(String[] args){
        ABC160C();
    }
    private static void ABC160C() {
        // no comment, no error check
        final int INPUT_LINES_CNT = 2;
        final String DATA_SPLIT_SPACE = " ";

        ArrayList<String> inputLines = getStdInMultiLines(INPUT_LINES_CNT);

        if (inputLines.size() == 0) {
            System.out.println(0);
            return;
        }

        String outputStr = "0";
        try {
            List<String> inputLineList= 
            Arrays.asList((inputLines.get(0)).split(DATA_SPLIT_SPACE));

            int distance = Integer.valueOf(Arrays.asList((inputLines.get(0)).split(DATA_SPLIT_SPACE)).get(0));
            int houseNum = Integer.valueOf(Arrays.asList((inputLines.get(0)).split(DATA_SPLIT_SPACE)).get(1));
            List<String> individualDistance = Arrays.asList((inputLines.get(1)).split(DATA_SPLIT_SPACE));
            int min = Integer.valueOf(individualDistance.get(houseNum - 1)) - Integer.valueOf(individualDistance.get(0));

            for (int i = 1; i < houseNum; i++){
                int temp = 0;
                temp = Integer.valueOf(individualDistance.get(i - 1)) + distance - Integer.valueOf(individualDistance.get(i));
                min = temp < min ? temp : min;
                outputStr = String.valueOf(min); 
            }
        }
        catch (Exception ex) {
            outputStr = "0";
        }

        System.out.println(outputStr);
        return;
    }

    private static int getStdInNum() {
        String line1 = getStdInSingleLine();
        if (isNumber(line1)) {
            return Integer.parseInt(line1);
        }
        return 0;
    }

    private static ArrayList<String> getStdInMultiLines() {
        int cnt = 0; 
        int max = 0;

        Scanner cin = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<String>();
        for (;cin.hasNext();) {
            list.add(cin.nextLine());
            if (cnt++ == 0) {
                max = Integer.parseInt((list.get(0)).split(" ")[0]);
            }
            else if (cnt == max + 1) {
                break;
            }
        }
        cin.close();
        return list;
    }
    private static ArrayList<String> getStdInMultiLines(int inputLinesCnt) {
        int cnt = 0; 

        Scanner cin = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<String>();
        for (;cin.hasNext();) {
            list.add(cin.nextLine());
            if (++cnt == inputLinesCnt) {
                break;
            }
        }
        cin.close();
        return list;
    }

    private static String getStdInSingleLine() {
        Scanner cin = new Scanner(System.in);

        for (;cin.hasNext();) {
            cin.close();
            return cin.nextLine();
        }

        cin.close();
        return "";
    }

    private static boolean isNumber(String val) {
        try {
            Integer.parseInt(val);
            return true;
        }
        catch (NumberFormatException nfex) {
            return false;
        }
    }

}
