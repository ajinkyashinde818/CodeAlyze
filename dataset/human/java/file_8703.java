import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = new int[2];
        array[0] = sc.nextInt();
        array[1] = sc.nextInt();
        int k = sc.nextInt();
        Arrays.sort(array);
        int aux = array[0] + 1;
        int cont = 0;

        while (true) {
            if (array[1] % aux == 0 && array[0] % aux == 0) {
                cont++;
                if(cont == k) {
                    break;
                }
            }
            aux--;
        }
        System.out.println(aux);
    }
}
