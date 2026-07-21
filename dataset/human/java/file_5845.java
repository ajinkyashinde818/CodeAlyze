import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws Exception {

        try {

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            String input = br.readLine();

            String result = "No";
            if (input.contains("a") && input.contains("b") && input.contains("c")) {
                result = "Yes";
            }

            System.out.println(result);
        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
            System.exit(0);
        } catch (final Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
    }

    private static int selectFee(int ticketForOnce, int unlimitedRide) {
        int selectedFee = ticketForOnce;
        if (ticketForOnce > unlimitedRide) {
            selectedFee = unlimitedRide;
        }

        return selectedFee;
    }
}
