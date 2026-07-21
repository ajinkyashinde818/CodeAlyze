import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();
        int[][] nums = new int[input][2];
        for (int i = 0; i < input; i++) {
            for (int j = 0; j < 2; j++) {
                nums[i][j] = scanner.nextInt();
            }
        }

        scanner.close();

        int count = 0;
        for(int[] a:nums){
            if(a[0]== a[1]){
                count++;
                if(count ==3){
                    System.out.println("Yes");
                    return;
                }
            }else{
                count = 0;
            }
        }

        System.out.println("No");

    }

}
