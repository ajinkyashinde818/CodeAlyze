import java.util.Scanner;

public class Main {

    //Equal
    
    public static boolean Equal(int X, int Y, int M, char A[][], char B[][]) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (!(A[X + i][Y + j] == B[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
    
    //Main

    public static void main(String args[]) throws Exception {

        Scanner Input = new Scanner(System.in);

        int N = Input.nextInt();
        int M = Input.nextInt();

        char A[][] = new char[N][N];
        char B[][] = new char[M][M];

        String S = "";
        String SS = "";
        String SSS = "";
        
        //System.out.println("AAAAA");
        
        for (int I = 0; I < A.length; I++) {
            S = Input.next();
            for (int J = 0; J < A[0].length; J++) {
                A[I][J] = S.charAt(J);
                //System.out.print(A[I][J]);
            }
            //System.out.println("");
        }
        for (int I = 0; I < B.length; I++) {
            S = Input.next();
            for (int J = 0; J < B[0].length; J++) {
                B[I][J] = S.charAt(J);
                //System.out.print(B[I][J]);
            }
            //System.out.println("");
        }

        boolean T = false;

        for (int I = 0; I < N - M + 1; I++) {
            for (int J = 0; J < N - M + 1; J++) {
                if (Equal(I, J, M, A, B)) {
                   //System.out.println("Yes");
                    T = true;
                    break;
                }
            }
        }
        
        //Cat

        if (T) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }
}
