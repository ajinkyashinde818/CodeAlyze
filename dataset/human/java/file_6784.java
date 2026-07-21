import java.util.*;

public class Main {
    public static int sum(ArrayList<Integer> a){
        int total = 0;
        for(int number : a){
            total += number;
        }
        return total;
    }

    public static int min(ArrayList<Integer> a){
        int min_num = 1000000000;
        for(int number : a){
            if(min_num > number){
                min_num = number;
            }
        }
        return min_num;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int total_distance = sc.nextInt();
        int number_of_points = sc.nextInt();
        ArrayList<Integer> points = new ArrayList<>();
        ArrayList<Integer> point_distance = new ArrayList<>();
        for(int i=0;i < number_of_points;i++){
            int number = sc.nextInt();
            points.add(number);
        }
        for(int i=0;i < number_of_points;i++){
            if(i == 0){
                point_distance.add(points.get(number_of_points-1) - points.get(0));
            }else{
                point_distance.add(total_distance - points.get(i) + points.get(i-1));
            }
        }
        System.out.println(min(point_distance));
    }
}
