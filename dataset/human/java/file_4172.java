import java.io.*;
import java.util.*;

public class Main {
  public static void main(String... args) {
    BufferedReader br = new BufferedReader(
      new InputStreamReader(System.in));

    try {
      int n = Integer.parseInt(br.readLine());
      String[] dishes = br.readLine().split(" ");
      String[] points = br.readLine().split(" ");
      String[] bonuses = br.readLine().split(" ");
      int total = 0;
      int nowDish = 0;
      int nowDishPoint = 0;
      int postDish = 0;
      int postDishBonus = 0;

      for(int i = 0; i < n; i++) {
        nowDish = Integer.parseInt(dishes[i]);
        nowDishPoint = Integer.parseInt(points[nowDish - 1]);
        
        if(nowDish > 1) {
          postDishBonus = Integer.parseInt(bonuses[nowDish - 2]);
        }

        if(i == 0 || nowDish != postDish + 1) {
          total += nowDishPoint;
        } else {
          total += nowDishPoint + postDishBonus;
        }

        if(i < n - 1) {
          postDish = nowDish;
        }
      }
      System.out.println(total);
      br.close();
    } catch(IOException e) {
      e.printStackTrace();
    }
  }
}
