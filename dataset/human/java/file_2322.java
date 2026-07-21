import java.util.*;

public class Main {
    private static final String STATIONS;

    static {
        String first = "abcdefghijklmnopqrstuvwxyz";
        String latter = first.toUpperCase();
        String stations = first.concat(latter);
        STATIONS = stations.concat(stations);
    }

    public static void main(String[] args) {
        try(Scanner scn = new Scanner(System.in)) {
            int n = 0;
            while((n = scn.nextInt()) > 0) {
                int[] keys = new int[n];
                for(int i = 0; i < n; i++) {
                    keys[i] = scn.nextInt();
                }

                StringBuilder sb = new StringBuilder();
                char[] list = scn.next().toCharArray();
                for(int i = 0; i < list.length; i++) {
                    sb.append(STATIONS.charAt(STATIONS.lastIndexOf(list[i]) - keys[i % n]));
                }
                System.out.println(sb);
            }
        }
    }
}
