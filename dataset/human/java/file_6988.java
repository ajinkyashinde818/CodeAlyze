import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    
    int K = scanner.nextInt();
    int N = scanner.nextInt();
    int locations[] = new int[N];
    
    for(int i = 0;i < locations.length;i++){
      locations[i] = scanner.nextInt();
    }
    
    int sumDistance = 0;
    int maxDistance = locations[1] - locations[0];
    sumDistance += maxDistance;
    
    for(int i = 2;i <= locations.length;i++){
        
      int distance;
      if(i == locations.length){
        distance = Math.abs(K - locations[i - 1]) + locations[0];
      }else{
      	distance = Math.abs(locations[i - 1] - locations[i]);
      }
      sumDistance += distance;
      if(distance > maxDistance){
        maxDistance = distance;
      }
      
      
    }
    
    sumDistance -= maxDistance;
    System.out.println(sumDistance);
  }
}
