import java.io.BufferedReader;
import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;
import java.util.Arrays;

public class Main {
	public static void main(final String[] args){
    
    final Scanner sc = new Scanner(System.in);
    final List<Integer> list = new ArrayList<>();
    final List<Integer> list2 = new ArrayList<>();
    //final List<Long> list3 = new ArrayList<>();

    int n = sc.nextInt();
    int count = 0;
    int check = 0;

    for(int i = 0; i < n ; i++){
        list.add(sc.nextInt());
        list2.add(sc.nextInt());
    }

    for(int i = 0; i < n ; i++){
        if(list.get(i).equals(list2.get(i))){
            count++;
        }else{
            count = 0;
        }
        if(count == 3){
            check++;
        }
    }

    if(check == 0){
        System.out.println("No");
    }else{
        System.out.println("Yes");
    }

    

   

    

    




    







}
}
