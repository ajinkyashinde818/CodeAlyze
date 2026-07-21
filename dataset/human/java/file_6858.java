import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author wnqmw
 */
public class Main {
    public static void main(String args[]){
        Scanner kb = new Scanner(System.in);
        
        int length = kb.nextInt(), numhouses = kb.nextInt();
        
        int[] houses = new int[numhouses];
        for(int i = 0; i < numhouses; i++){
            houses[i] = kb.nextInt();
        }
        
        int max = houses[0]+(length-houses[numhouses-1]);
        for(int i = 1; i < numhouses; i++){
            if(max < houses[i]-houses[i-1]){
                max = houses[i]-houses[i-1];
            }
        }
        System.out.println(length-max);
    }
}
