import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[100];
        for(int i = 0;i < n;i++){
            array[sc.nextInt() - 1]++;
        }
        int score = 0;
        for(int i = 0;i < array.length;i++){
            int count = 0;
            for(int j = array.length - 1;j >= score;j--){
                count += array[j];
            }
            if(count > score && count > 0){
                score = i + 1;
            }
        }
        System.out.println(score);
    }
}
