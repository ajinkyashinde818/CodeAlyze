import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[] input = sc.next().toCharArray();
        boolean flag = false;
        loop: for(char c: input){
            if(c == '9'){
                flag = true;
                break loop;
            }
        }
        if(flag){
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static void printArray(int[] array){
        for(int i=0; i<array.length; i++){
            if(i == array.length){
                System.out.println(array[i]);
            } else {
                System.out.print(String.format("%d ", array[i]));
            }
        }
    }
}
