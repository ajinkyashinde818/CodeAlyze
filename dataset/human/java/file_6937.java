import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int whole = sc.nextInt();
        int houses = sc.nextInt();
        List<Integer> houseList = new ArrayList<>();
        for(int i = 1;i <= houses;i++){
            houseList.add(sc.nextInt());
        }

	    int result = execute(whole,houses,houseList);
        System.out.println(result);
    }

    public static int execute(int whole,int houseSize, List<Integer> houseList){
        int lastDistance = whole - houseList.get(houseList.size() - 1);
        List<Integer> distanceList = new ArrayList<>();
        for(int i = 0;i < houseSize;i++){
            int beforeHounse = houseList.get(i);
            int next = i + 1;
            if(next == houseSize){
                next = 0;
            }
            int afterHouse = houseList.get(next);
            int distance = afterHouse - beforeHounse;
            if(distance < 0){
                distance += whole;
            }
            distanceList.add(distance);
        }
        int result = 0;
        int maxDistance = 0;
        for(Integer distance : distanceList){
            result = result + distance;
            maxDistance = Math.max(maxDistance,distance);
        }
        result = result - maxDistance;
        return result;
    }
}
