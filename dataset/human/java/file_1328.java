import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int ns[][] = new int[n][n];
        int ms[][] = new int[m][m];
        for (int y = 0;y < n;++y){
            String s = sc.next();
            for (int x = 0;x < n;++x){
                ns[x][y] = s.charAt(x) == '#' ? 1 : 0;
            }
        }
        for (int y = 0;y < m;++y){
            String s = sc.next();
            for (int x = 0;x < m;++x){
                ms[x][y] = s.charAt(x) == '#' ? 1 : 0;
            }
        }
        for (int y = 0;y <= n - m;++y){
            for (int x = 0;x <= n - m;++x){
                boolean flag = true;
                for (int y2 = 0;y2 < m;++y2){
                    for (int x2 = 0;x2 < m;++x2){
                        if(ns[x + x2][y + y2] != ms[x2][y2]) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)break;
                }
                if(flag) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }


}
