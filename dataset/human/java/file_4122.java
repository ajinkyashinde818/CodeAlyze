import java.util.*;
 
public class Main{
	public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int number = sc.nextInt();
    int[] junban = new int[number];
    int[] manzoku = new int[number];
    int[] addManzoku = new int[number-1];
    int sumManzoku = 0;
    for(int i = 0; i < number; i++){
    	junban[i] = sc.nextInt();
    }
    for(int j = 0; j < number; j++){
    	manzoku[j] = sc.nextInt();
        sumManzoku += manzoku[j];
    }
    for(int k = 0; k < number-1; k++){
    	addManzoku[k] = sc.nextInt();
    } 
    for(int l = 1; l < number; l++){
      if(junban[l]-1 == junban[l-1]){
      	sumManzoku += addManzoku[junban[l-1]-1];
      }
    }
    System.out.println(sumManzoku);
    }
}
