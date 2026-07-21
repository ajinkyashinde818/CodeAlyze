import java.io.*;
import java.util.*;

public class Main {
        public static void main(String[] args) {
                Scanner scan = new Scanner(System.in);

                int N = scan.nextInt();
                long K = scan.nextLong();

                int[] town_to = new int[N];

                for (int i = 0; i < N; i++) {
                        town_to[i] = scan.nextInt();
                }

                int[] flag = new int[N];

                int now_town = 1;

                long k = K;

                for (int j = 0; j < K; j++) {
                        flag[now_town-1] = 1;
                        now_town = town_to[now_town-1];
                        k--;
                        if (flag[now_town-1] == 1) {
                                break;
                        }
                }

                long count = 0;

                if (k != 0) {
                        while (true) {
                                flag[now_town-1] = 0;
                                now_town = town_to[now_town-1];
                                count++;
                                k--;
                                if (k == 0) {
                                        break;
                                }
                                if (flag[now_town-1] == 0) {
                                break;
                                }
                        }
                }

                if (k == 0) {
                        System.out.println(now_town);
                } else {
                        long nokori = k%count;
                        if (nokori == 0) {
                                System.out.println(now_town);
                        } else {
                                for (long index = 1; index <= nokori; index++) {
                                        now_town = town_to[now_town-1];
                                }
                                System.out.println(now_town);
                        }
                }
        }
}
