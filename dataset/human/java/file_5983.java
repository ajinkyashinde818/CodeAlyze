import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rn-sshawish
 */
public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean [] state = new boolean[3];
        String s = input.nextLine();
        for (int i = 0; i < 3; i++) {
            state[s.charAt(i) - 'a'] = true;
        }
        boolean isPer = true;
        for (int i = 0; i < 3; i++) {
            isPer &= state[i];
        }
        System.out.println(isPer? "Yes" : "No");
    }
}
