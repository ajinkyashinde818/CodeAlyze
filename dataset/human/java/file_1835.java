import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

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
        ABC104_C solver = new ABC104_C();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC104_C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long goal = in.nextLong();

            int ans = Integer.MAX_VALUE;
            int[] problems = new int[n];
            long[] bonus = new long[n];
            Problem[] set = new Problem[n];
            for (int i = 0; i < n; i++) {
                problems[i] = in.nextInt();
                bonus[i] = in.nextLong();

                Problem pro = new Problem((i + 1) * 100, problems[i], bonus[i]);
                set[i] = pro;
            }

            List<List<Integer>> searchList = new ArrayList<List<Integer>>();


            searchList = getBinary(n);


            for (List<Integer> list : searchList) {
                long score = 0;
                int cnt = 0;
                int index = 0;
                for (Integer solve : list) {
                    if (solve == 1) {
                        score += set[index].perfect;
                        cnt += set[index].cnt;
                    }
                    index++;
                }

                if (score >= goal) {
                    ans = Math.min(ans, cnt);
                } else {
                    for (index = list.size() - 1; 0 <= index; index--) {
                        if (list.get(index) == 0) {
                            long sub = goal - score;
                            if (set[index].point * (set[index].cnt - 1) < sub) {
                                break;
                            } else {
                                cnt += sub / set[index].point;
                                if (sub % set[index].point != 0) {
                                    cnt++;
                                }
                                ans = Math.min(ans, cnt);
                                break;
                            }
                        }
                    }

                }


            }
            out.print(ans);

        }

        private List<List<Integer>> getBinary(int n) {

            if (n == 1) {
                List<List<Integer>> list = new ArrayList<List<Integer>>();
                List<Integer> addZero = new ArrayList<Integer>();
                List<Integer> addOne = new ArrayList<Integer>();

                addZero.add(0);
                addOne.add(1);

                list.add(addZero);
                list.add(addOne);

                return list;
            }

            List<List<Integer>> prev = getBinary(n - 1);
            List<List<Integer>> returnArray = new ArrayList<List<Integer>>(prev);
            for (List<Integer> array : prev) {
                List<Integer> addZero = new ArrayList<Integer>(array);
                List<Integer> addOne = new ArrayList<Integer>(array);

                addZero.add(0);
                addOne.add(1);

                returnArray.add(addZero);
                returnArray.add(addOne);

                returnArray.remove(array);
            }

            return returnArray;
        }

    }

    static class Problem {
        int point;
        int cnt;
        long bonus;
        long perfect;

        Problem(int point, int cnt, long bonus) {
            this.point = point;
            this.cnt = cnt;
            this.bonus = bonus;
            this.perfect = this.point * this.cnt + this.bonus;
        }

    }
}
