import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++){
            array[i] = scanner.nextInt();
        }

        int min = k;
        for (int i = 0; i < n - 2; i++){
            //反時計回りを試す
            //
            int temp = 0;
//            if (i == n -1){
//                temp = array[n-1] - array[0];
//            }
//            else{
                temp = array[i];
                temp += k - array[i+1];
//            }

//            System.out.println(temp);
            if (temp < min){
                min = temp;
            }
        }

        boolean isFirst = true;

        for (int i = 0; i < n; i++){
            int temp = 0;
            if (isFirst){
                temp = array[n-1] - array[0];
                isFirst = false;
            }else{
                temp = k - array[i];
                temp += array[i-1];
            }


//            System.out.println(temp);
            if (temp < min){
                min = temp;
            }
        }
//        System.out.println();
        System.out.println(min);





    }
}
