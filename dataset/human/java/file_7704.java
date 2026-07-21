import java.text.Bidi;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long k = sc.nextLong();

        //System.out.println("n = " + n);
        //System.out.println("k = " + k);

        int[] towns = new int[n];
        for(int i = 0; i < n; i++){
            towns[i] = sc.nextInt();
        }

        int nextPlace = 1;
        HashMap<Integer, Integer> visitedPlaces = new HashMap<>(); //<K,V> = <town, index>
        ArrayList<Integer> visitedPlacesList = new ArrayList<>();
        visitedPlacesList.add(nextPlace);
        visitedPlaces.put(nextPlace, 0);

        int reIndex = 0;
        int loopSize = 0;
        int visitCount = 0;
        for(int i = 1; i < n+1; i++) {
            nextPlace = towns[nextPlace - 1];
            if (visitedPlaces.containsKey(nextPlace)) {
                reIndex = visitedPlaces.get(nextPlace);
                loopSize = visitedPlaces.size() - reIndex;
                break;
            }
            visitCount++;
            visitedPlaces.put(nextPlace, i);
            visitedPlacesList.add(nextPlace);
            if(i == k){
                System.out.println(nextPlace);
                return;
            }
        }

        int rem = (int)((k-visitCount) % loopSize);

        //System.out.println("rem = " + rem);
        //System.out.println("visitCount = " + visitCount);
        //System.out.println("reIndex = " + reIndex);
        //System.out.println("loopSize = " + loopSize);

        //for(int e : visitedPlaces){
        //    System.out.print(e + " ");
        //}
        //System.out.println();

        if(rem == 0) {
            System.out.println(visitedPlacesList.get(visitedPlacesList.size() - 1));
        }else{
            System.out.println(visitedPlacesList.get(reIndex + rem - 1));
        }
    }
}
