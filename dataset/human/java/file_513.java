import java.util.*;
import java.util.Scanner;
class Main{
    public static void main(String[] args)
    {
        int contestNumberOfTimes;
        int rating;
        int ratingResult;
        
        Main main = new Main();
        Scanner scanner = new Scanner(System.in);
        contestNumberOfTimes = scanner.nextInt();
        rating = scanner.nextInt();
        ratingResult = rating + main.Calculation(contestNumberOfTimes);

        System.out.println(ratingResult);
    }
    public int Calculation(int contentsNumber){
        int result;
        if(contentsNumber < 10){
            result = 100 * (10 - contentsNumber);
        }else{
            result = 0;
        }
        return result;
    }
}
