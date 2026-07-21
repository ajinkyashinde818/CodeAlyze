import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            String s = reader.readLine();
            String t = reader.readLine();

            Character[] sc = toCharacterArray(s);

            Character[] tc = toCharacterArray(t);

            // s 昇順
            Arrays.sort(sc);

            // t 降順
            Arrays.sort(tc, Comparator.reverseOrder());

            s = "";
            for (Character c : sc) s += c.toString();

            t = "";
            for (Character c : tc) t += c.toString();

            System.out.println(s.compareTo(t) < 0 ? "Yes" : "No");
        }
    }

    static Character[] toCharacterArray( String s ) {
        if ( s == null ) {
            return null;
        }

        int len = s.length();
        Character[] array = new Character[len];
        for (int i = 0; i < len ; i++) {
            array[i] = new Character(s.charAt(i));
        }

        return array;
    }
}
