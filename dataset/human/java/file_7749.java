import java.util.*;

public class Main {

    static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}
    static int mod = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long K = sc.nextLong();
        long[] A = new long[(int) N];
        long[] teleported = new long[(int) N];

        for(int i=0;i<N;i++){
            A[i] = sc.nextInt();
            teleported[i] = -1;
        }

        long currentPoint = 1;
        teleported[0] = 0;
        long warpCount = 0;
        long loop;
        long restOfLoop =0;
        for(long i=0;i<Math.min(N,K);i++){
            warpCount++;
            currentPoint = A[(int) (currentPoint-1)];

            if(teleported[(int) (currentPoint-1)] == -1){
                teleported[(int) (currentPoint-1)] = warpCount;
            } else {
                loop = warpCount - teleported[(int) (currentPoint-1)];
                restOfLoop = (K - teleported[(int) (currentPoint-1)]) % loop;
                break;
            }
        }

        for(long i=0;i<restOfLoop;i++){
            currentPoint = A[(int) (currentPoint-1)];
        }

        System.out.println(currentPoint);

    }

}
