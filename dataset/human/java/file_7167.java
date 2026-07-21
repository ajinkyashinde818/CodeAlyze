import java.util.Arrays;
import java.util.Scanner;

/**
 * @author yoshizaki
 *
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        int lake = scanner.nextInt();
        int house = scanner.nextInt();
        int[] position = new int[house];
        for(int i = 0; i < house; i++) position[i] = scanner.nextInt();
        int[] distance = new int[house];
        distance[0] = lake - position[house - 1] + position[0];
        for(int i = 1; i < house; i++) {
        	distance[i] = position[i] - position[i - 1];
        }
        int ans = Arrays.stream(distance).sum() - Arrays.stream(distance).max().getAsInt();
        System.out.println(ans);
    }

}
