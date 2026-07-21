import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        StringBuilder other = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != 'x') other.append(s.charAt(i));
        }
        if (!isPalin(other.toString())) System.out.println(-1);
        else {
            System.out.println(additions(s));
        }
    }

    private static boolean isPalin(String s){
        int upto = s.length() % 2 == 0?s.length()/2 - 1:s.length()/2;

        for (int i = 0; i <= upto; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) return false;
        }
        return true;
    }

    private static int additions(String s){
        int i = 0;
        int j = s.length() - 1;
        int count = 0;

        while (i < j){
            if(s.charAt(i) == s.charAt(j)){
                i++;
                j--;
            }
            else if (s.charAt(i) == 'x'){
                i++;
                count++;
            }
            else {
                j--;
                count++;
            }
        }

        return count;
    }
}
