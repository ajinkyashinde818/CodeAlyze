import java.util.Scanner;

public class Main {

    public Main() {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long K = scan.nextLong();

        int[] A = new int[N];
        for (int i=0;i<N;i++){
            A[i] = scan.nextInt()-1;
        }

        boolean[] P = new boolean[N];

        int index = 0;
        int num = 0;
        while(true){
            if(P[A[index]]){
                index = A[index];
                K -= num+1;
                break;
            }
            P[index] = true;

            index = A[index];
            num++;
            if(num == K){
                System.out.println(index+1);
                return;
            }
        }

        int start = index;

        //閉路の長さを求める
        int L = 1;
        while(true){
            if(!P[index]) break;
            L++;
            P[index] = false;
            index = A[index];
        }

        K = K % L;
        index = start;
        for(int i=0;i<K;i++){
            index = A[index];
        }

        System.out.println(index+1);

    }

    public static void main(String[] args) {
	    Main main = new Main();
    }
}
