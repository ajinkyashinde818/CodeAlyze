import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            if (solve(in.next())) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

        public boolean solve(String input) {
            String word = input + "$";

            int totalStates = 5;
            int[] statePos = new int[totalStates];
            boolean[] activeStates = new boolean[totalStates];
            activeStates[0] = true;
            boolean atLeastOnActiveState = true;
            while (atLeastOnActiveState) {

                atLeastOnActiveState = false;
                boolean[] newStates = new boolean[totalStates];
                for (int stateId = 0; stateId < totalStates - 1; stateId++) {
                    if (activeStates[stateId]) {
                        atLeastOnActiveState = true;
                        processState(stateId, statePos, newStates, word);
                    }
                }

                if (newStates[4]) {
                    return true;
                }

                activeStates = newStates;
            }

            return false;
        }

        private void processState(int stateId, int[] statePos, boolean[] newStates, String word) {
            int startIdx = statePos[stateId];
            int nextStatePos = 0;
            switch (stateId) {
                case 0:
                    if ((nextStatePos = matchString(word, "dream", startIdx)) > 0) {
                        newStates[1] = true;
                        statePos[1] = nextStatePos;
                        newStates[0] = true;
                        statePos[0] = nextStatePos;
                    } else if ((nextStatePos = matchString(word, "er", startIdx)) > 0) {
                        newStates[2] = true;
                        statePos[2] = nextStatePos;
                    } else if ((nextStatePos = matchString(word, "$", startIdx)) > 0) {
                        newStates[4] = true;
                    }
                    break;
                case 1:
                    if ((nextStatePos = matchString(word, "er", startIdx)) > 0) {
                        newStates[0] = true;
                        statePos[0] = nextStatePos;

                        newStates[2] = true;
                        statePos[2] = nextStatePos;
                    } else if ((nextStatePos = matchString(word, "$", startIdx)) > 0) {
                        newStates[4] = true;
                    }
                    break;
                case 2:
                    if ((nextStatePos = matchString(word, "as", startIdx)) > 0) {
                        newStates[3] = true;
                        statePos[3] = nextStatePos;
                    }
                    break;
                case 3:
                    if ((nextStatePos = matchString(word, "er", startIdx)) > 0) {
                        newStates[0] = true;
                        statePos[0] = nextStatePos;
                    } else if ((nextStatePos = matchString(word, "e", startIdx)) > 0) {
                        newStates[0] = true;
                        statePos[0] = nextStatePos;
                    }
                    break;
            }
        }

        private int matchString(String word, String target, int startIdx) {
            if (startIdx + target.length() > word.length()) {
                return -1;
            }

            for (int i = 0; i < target.length(); i++) {
                if (word.charAt(startIdx + i) != target.charAt(i)) {
                    return -1;
                }
            }

            return startIdx + target.length();
        }

    }
}
