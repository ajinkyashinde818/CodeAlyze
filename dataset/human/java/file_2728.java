import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        int n = s.length();
        int m = t.length();
        char[] sChar = s.toCharArray();
        char[] tChar = t.toCharArray();
        Arrays.sort(sChar);
        Arrays.sort(tChar);
        reverse(tChar, 0, tChar.length - 1);
        System.out.println(String.valueOf(sChar).compareTo(String.valueOf(tChar)) < 0 ? "Yes" : "No");

    }
    public static void reverse(char[] arr, int l, int r) {
        if (l >= r) return;
        char temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        reverse(arr, l + 1, r - 1);
    }
}
