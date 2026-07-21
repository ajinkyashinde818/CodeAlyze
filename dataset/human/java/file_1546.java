import java.util.*;
import java.lang.*;



public class Main {
    static void possible(){
        System.out.println("Yes");
        System.exit(0);
    }
    static void impossible(){
        System.out.println("No");
        System.exit(0);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        char[][] picture = new char[N][N];
        for(int h=0; h<N; h++) {
            String line = sc.next();
            for(int w=0; w<N; w++) picture[h][w]=line.charAt(w);
        }

        char[][] pattern = new char[M][M];
        for(int h=0; h<M; h++) {
            String line = sc.next();
            for(int w=0; w<M; w++) pattern[h][w]=line.charAt(w);
        }

        for(int cx=0; cx<=N-M; cx++) for(int cy=0; cy<=N-M; cy++){
            boolean match = true;
            for(int dx=0; dx<M; dx++) for(int dy=0; dy<M; dy++){
                if(picture[cx+dx][cy+dy]!=pattern[dx][dy]) match=false;
            }
            if(match) possible();
        }
        impossible();

    }
}
