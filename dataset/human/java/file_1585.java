import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] mapA = new char[n][n];
        char[][] mapB = new char[n][n];
        for(int i = 0; i < n; i++){
            mapA[i] = sc.next().toCharArray();
        }
        for(int i = 0; i < m; i++){
            mapB[i] = sc.next().toCharArray();
        }
        int len = n-m+1;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                boolean bool = true;
                for(int k = 0; k < m; k++){
                    for(int l = 0; l < m; l++){
                        if(mapA[i+k][j+l] != mapB[k][l]){
                            bool = false;
                            break;
                        }
                    }
                    if(!bool) break;
                }
                if(bool){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}
