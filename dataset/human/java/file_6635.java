import java.util.*;

public class Main {
    static int[] vx = {1,0,-1,0};
    static int[] vy = {0,1,0,-1};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int x = sc.nextInt();
        int y = sc.nextInt();

        ArrayList<Integer> vx = new ArrayList<>();
        ArrayList<Integer> vy = new ArrayList<>();
        int xpp = 0;
        boolean f = true;
        boolean nx = true;
        int tmp = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'F') {
                if(f) {
                    xpp++;
                } else {
                    tmp++;
                }
            } else {
                if(f) {
                    f = false;
                } else {
                    if(nx) {
                        vx.add(tmp);
                    } else {
                        vy.add(tmp);
                    }
                }
                tmp = 0;
                nx = !nx;
            }
        }
        if(nx) {
            vx.add(tmp);
        } else {
            vy.add(tmp);
        }
        boolean[][] dpx = new boolean[vx.size() + 1][20000];
        boolean[][] dpy = new boolean[vy.size() + 1][20000];
        dpx[0][10000 + xpp] = true;
        dpy[0][10000] = true;
        for(int i = 0; i < vx.size(); i++) {
            int t = vx.get(i);
            for(int j = 0; j < 20000; j++) {
                if(j + t < 20000) {
                    dpx[i + 1][j + t] |= dpx[i][j];
                }
                if(j - t >= 0) {
                    dpx[i + 1][j - t] |= dpx[i][j];
                }
            }
        }
        for(int i = 0; i < vy.size(); i++) {
            int t = vy.get(i);
            for(int j = 0; j < 20000; j++) {
                if(j + t < 20000) {
                    dpy[i + 1][j + t] |= dpy[i][j];
                }
                if(j - t >= 0) {
                    dpy[i + 1][j - t] |= dpy[i][j];
                }
            }
        }

        boolean ans = dpy[dpy.length - 1][y + 10000] && dpx[dpx.length-1][x + 10000];


        if(ans) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
