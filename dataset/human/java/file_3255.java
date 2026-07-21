import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws Exception {

        try {

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            String inputString = br.readLine();

            String isContainNine = "No";
            if (inputString.charAt(0) == '9' || inputString.charAt(1) == '9') {
                isContainNine = "Yes";
            }

            System.out.println(isContainNine);

        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
            System.exit(0);
        } catch (final Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
    }
}
