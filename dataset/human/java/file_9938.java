import java.util.*;

public class Main{
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int X = scanner.nextInt();

        int C[] = new int[N];
        int A[][] = new int[N][M];

        for(int loopN=0; loopN<N; loopN++){

            C[loopN] = scanner.nextInt();

            for(int loopM=0; loopM<M; loopM++){
                A[loopN][loopM] = scanner.nextInt();
            }
        }



        // 全冊読破で達成可能か判定
        for(int loopM=0; loopM<M; loopM++){
            int understand = 0;

            for(int loopN=0; loopN<N; loopN++){
                understand += A[loopN][loopM];
            }
            if(understand<X){
                System.out.println(-1);
                return;
            }
        }



        // 各パターンの理解度判定・コスト計算
        int maxCode = 1;
        int minCost = 0;
        for(int loop=0; loop<N; loop++){
            maxCode *= 2;
            minCost += C[loop];
        }
        maxCode--;

        for(int loopCode=1; loopCode<maxCode; loopCode++){
            int code = loopCode;
            int bookN[] = new int[N];
            for(int loop=0; loop<N; loop++){
                bookN[loop] = code % 2;
                code /= 2;
            }

            // 理解度判定
            boolean canUnderstand = true;
            for(int loopM=0; loopM<M; loopM++){
                int understand = 0;

                for(int loopN=0; loopN<N; loopN++){
                    understand = understand + ( A[loopN][loopM] * bookN[loopN] );
                }
                if(understand<X){
                    canUnderstand = false;
                }
            }
            if( canUnderstand ){

                // コスト計算
                int cost=0;
                for(int loopN=0; loopN<N; loopN++){
                    cost = cost + ( C[loopN] * bookN[loopN] );
                }
                if(cost<minCost){
                    minCost = cost;
                }
            }
        }

        System.out.println( minCost );

    }
}
