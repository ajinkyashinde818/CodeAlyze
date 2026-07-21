import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();        
        sc.close();


        boolean b = false;
        int n1=0, n2=0;
        for(int i=1; i<1000; i++){
            if(i * (i+1) == n * 2){
                b = true;
                n1 = i;
                n2 = i+1;
                break;
            }
        }

        if(!b){
            System.out.println("No");
            return;
        }

        int[][] ans = new int[n2][n1];
        for(int i=0; i<n1; i++){
            ans[0][i] = i+1;
        }
        int c = n1+1;
        for(int i=1; i<n2; i++){
            for(int j=0; j<i; j++){
                ans[i][j] = ans[j][i-1];
            }
            for(int j=i; j<n1; j++){
                ans[i][j] = c;
                c++;
            }
        }

        System.out.println("Yes");
        System.out.println(n2);
        for(int i=0; i<n2; i++){
            System.out.print(n1);
            for(int j=0; j<n1; j++){
                System.out.print(" " + ans[i][j]);
            }
            System.out.println("");
        }

    }
}
