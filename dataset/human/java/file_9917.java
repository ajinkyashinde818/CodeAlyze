import java.util.Scanner;

public class Main {
    Book[] B;
    boolean[] isUse;
    int N,M,X;

    class Book{
        int C;
        int[] A;
        public Book(int C, int[] A){
            this.C = C;
            this.A = A;
        }
    }

    public Main() {
        Scanner scan = new Scanner(System.in);
        N = Integer.parseInt(scan.next());
        M = Integer.parseInt(scan.next());
        X = Integer.parseInt(scan.next());

        isUse = new boolean[N];
        B = new Book[N];

        for(int i=0;i<N;i++){
            int C = Integer.parseInt(scan.next());
            int[] A = new int[M];
            for (int j=0;j<M;j++){
                A[j] = Integer.parseInt(scan.next());
            }
            B[i] = new Book(C, A);
        }
        int minCost = search(0);
        if(minCost == Integer.MAX_VALUE){
            System.out.println(-1);
        } else {
            System.out.println(minCost);
        }
    }

    public int search(int index){
        if(index == N){
            int cost = 0;
            int[] temp = new int[M];
            for(int i=0;i<N;i++){
                if(isUse[i]) {
                     cost += B[i].C;
                    for (int j = 0; j < M; j++) {
                        temp[j] += B[i].A[j];
                    }
                }
            }

            for (int j = 0; j < M; j++) {
                if(temp[j] < X){
                    return Integer.MAX_VALUE;
                }
            }

            return cost;
        }
        isUse[index] = true;
        int use = search(index+1);
        isUse[index] = false;
        int noUse = search(index+1);

        return Math.min(use, noUse);
    }

    public static void main(String[] args) {
	    Main main = new Main();
    }
}
