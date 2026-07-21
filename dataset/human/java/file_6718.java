import java.util.*;
public class Main {
  
	public static void main(String[] args) {
      
    	Scanner sc = new Scanner(System.in);
      	int k = sc.nextInt();
      	int n = sc.nextInt();
      	int maxDistance = 0;
      	int newPoint;
      	int lastPoint = sc.nextInt();
      	int firstPoint = lastPoint;
      	int distance;
      	for (int i = 0; i <  n; i++) {
          if (i == n - 1) {
            newPoint = firstPoint + k;
          } else {
          	newPoint = sc.nextInt();
          }
          distance = Math.abs(newPoint - lastPoint);
          lastPoint = newPoint;
          maxDistance = maxDistance < distance ? distance : maxDistance;
        }
      System.out.println(k - maxDistance);
    }
 }
