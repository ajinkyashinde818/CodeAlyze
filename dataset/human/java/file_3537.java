import java.util.*;

public class Main{

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
        String X = sc.next();
        String Y = sc.next();
        String[] xy = {X,Y};
      
        int x = 0;
        int y = 0;
        for(int i = 0; i < 2; i++){
          switch(xy[i]){
            case "A": 
              if(x == 0){
                x = 10;
              }else{
                y = 10;
              }
              break;
            case "B":
              if(x == 0){
                x = 11;
              }else{
                y = 11;
              }
              break;
            case "C":
              if(x == 0){
                x = 12;
              }else{
                y = 12;
              }
              break;
            case "D":
              if(x == 0){
                x = 13;
              }else{
                y = 13;
              }
              break;
            case "E":
              if(x == 0){
                x = 14;
              }else{
                y = 14;
              }
              break;
            case "F":
              if(x == 0){
                x = 15;
              }else{
                y = 15;
              }
              break;
          }
        }
        
        if(x > y){
          System.out.println(">");
        }else if(x == y){
          System.out.println("=");
        }else{
          System.out.println("<");
        }
        
	}

}
