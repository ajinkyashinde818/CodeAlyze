import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Main {
    public static void main(final String[] args) throws Exception {

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));) {
            List<String> inputString = Arrays.asList(br.readLine().split(" "));
            List<Integer> numbers = new ArrayList<>();
            for (String str : inputString) {
                numbers.add(Integer.parseInt(str));
            }

            int ans = 0;
            for (int i = 0; i <= numbers.get(0); i++) {
                for (int j = 0; j <= numbers.get(0); j++) {
                    int k = numbers.get(1) - i - j;
                    if (0 <= k && k <= numbers.get(0)) {
                        ans++;
                    }
                }
            }

            System.out.println(ans);
        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
            System.exit(0);
        } catch (final Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
    }
}
