import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        int counter = 0;

        int[][] result = new int[n][2];
        for(int i=0; i < n; i++){
            result[i][0] = sc.nextInt();
            result[i][1] = sc.nextInt();
        }

        for(int i=0; i< n; i++){
            if(result[i][0] == result[i][1]){
                counter++;
                if(counter == 3){
                    break;
                }
            }else {
                counter = 0;
            }
        }

        if(counter == 3){
            System.out.println("Yes");
        }else {
            System.out.println(("No"));
        }

    }
}
