//time complexity O(n)
//space complexity O(n)


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {


    static int no_of_steps(int i, int[] memo) {
    if(i < 1)
        return 0;
    if(i <= 2)
        return i;
    if(i == 3)
        return 4;
    if(memo[i - 1] == 0)
        memo[i - 1] = no_of_steps(i - 3, memo) + no_of_steps(i - 2, memo) + no_of_steps(i - 1, memo);
    return memo[i - 1];
}

    // Complete the stepPerms function below.
    static int stepPerms(int n) {
        int[] memo = new int[n];
        return no_of_steps(n, memo);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int s = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int sItr = 0; sItr < s; sItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            int div = (int)(Math.pow(10, 10) + 0.5); 
            int res = stepPerms(n) % (div + 7);

            bufferedWriter.write(String.valueOf(res));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
