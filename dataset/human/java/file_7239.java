import java.util.*;

class Main{
    Main(){
        Scanner SC = new Scanner(System.in);

        int K = Integer.parseInt(SC.next());
        int N = Integer.parseInt(SC.next());

        int[] A = new int[2*N];

        for(int i=0;i<N;i++){
            A[i]   = Integer.parseInt(SC.next());
            A[N+i] = A[i] + K;
        }

        int min = Integer.MAX_VALUE;

        for(int i=0;i<N;i++){
            min = Math.min(min, A[N+i-1] - A[i]);
        }
        if(min == K) min = 0;
        System.out.println(min);
    }

    public static void main(String[] args){
        Main main = new Main();
    }
}
