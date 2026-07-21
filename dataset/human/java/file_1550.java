import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();


        String[] A = new String[ N ];
        for(int i = 0 ;i < N ; i ++){
            A[ i ] = sc.next();
        }

        String[] B = new String[ M ];
        for(int i = 0 ;i < M ; i ++){
            B[ i ] = sc.next();
        }

        boolean matchFlg = false;
        for (int i = 0; i < N - M + 1; i++) {
            for (int j = 0; j < N - M  + 1; j++) {
                if (matchFlg) {
                    break;
                }
                for (int k = 0 ; k < M; k++) {
                    if (!B[ k ].equals(A[i + k].substring(j,j + M))) {
                        matchFlg = false;
                        break;
                    }
                    matchFlg = true;
                }
            }
        }
        System.out.println(matchFlg ? "Yes" : "No");
    }
}
