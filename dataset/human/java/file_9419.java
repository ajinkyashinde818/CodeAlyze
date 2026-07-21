import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] dice = new int[2][n];
        for(int i = 0; i<n; i++){
            dice[0][i] = sc.nextInt();
            dice[1][i] = sc.nextInt();
        }

        int[] count = new int[n-2];
        for(int i = 0; i<n-2; i++){
            for(int j = i; j<i+3; j++){
                if(dice[0][j] == dice[1][j]){
                    count[i]++;
                }
            }
        }

        Arrays.sort(count);
        if(count[n-3] == 3){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }
}
