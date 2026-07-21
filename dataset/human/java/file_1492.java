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
            int N = Integer.parseInt(inputString.get(0));
            int M = Integer.parseInt(inputString.get(1));
            List<List<String>> nPicture = new ArrayList<>();
            List<List<String>> mPicture = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                nPicture.add(Arrays.asList(br.readLine().split("")));
            }

            for (int i = 0; i < M; i++) {
                mPicture.add(Arrays.asList(br.readLine().split("")));
            }

            boolean exist = false;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i + M - 1 >= N || j + M - 1 >= N) {
                        continue;
                    }

                    boolean match = true;
                    for (int k = 0; k < M; k++) {
                        for (int l = 0; l < M; l++) {
                            if(!nPicture.get(i + k ).get(j + l).equals(mPicture.get(k).get(l))) {
                                match = false;
                            }
                        }
                    }
                    if (match) exist = true;
                }
            }

            if (exist) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
            System.exit(0);
        } catch (final Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
    }
}
