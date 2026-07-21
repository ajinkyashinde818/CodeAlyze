import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
       
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int[] array1  = new int[a];
        int[] array2 = new int[a];
        int[] array3 = new int[a-1];
        int sum = 0;

        for(int i = 0; i < a; i++){
            array1[i] = sc.nextInt();
        }
        for(int i = 0; i < a; i++){
            array2[i] = sc.nextInt();
        }
        for(int i = 0; i < a - 1; i++){
            array3[i] = sc.nextInt();
        }
        for(int i = 0; i < a; i++){
            sum += array2[array1[i] - 1];
            if(i == (a - 1)){
                break;
            }
            if(array1[i] == (array1[i + 1] - 1)){
                sum += array3[array1[i] - 1];
            }
        }
        System.out.println(sum);
    }
}
