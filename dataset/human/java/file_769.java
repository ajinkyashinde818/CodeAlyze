import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


class Main {

    public static void main(String[] args) throws Exception {

        try {

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            List<String> input = Arrays.asList(br.readLine().split(" "));

            List<Integer> numbers = new ArrayList<>();
            for (String s : input) {
                numbers.add(Integer.parseInt(s));
            }

            int rating = numbers.get(1);

            if (numbers.get(0) < 10) {
                int internalRationg = (10 - numbers.get(0)) * 100;
                rating += internalRationg;
            }

            System.out.println(rating);
        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
            System.exit(0);
        } catch (final Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
    }
}
