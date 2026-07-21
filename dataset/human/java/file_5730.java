import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            final String s = reader.readLine();

            HashSet<Character> st = new HashSet<Character>();

            for (int i = 0; i < s.length(); i++) {
                st.add(s.charAt(i));
            }

            System.out.println(st.size() == 3 ? "Yes" : "No");
        }
    }
}
