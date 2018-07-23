import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    Scanner cin = new Scanner(new BufferedInputStream(System.in));
    // 使用cin进行输入的时候可能会比in快一些。
    while (in.hasNext()) { // 多组输入
        int x = in.nextInt();
        int n = in.nextInt();
        int k = in.nextInt();
        // 大数BigInteger
        BigInteger b = new BigInteger(x + "");
        BigInteger ans = BigInteger.valueOf(k);
        b = b.add(b);  // b = b + b
        b = b.subtract(b);  // b = b - b
        b = b.multiply(b);  // b = b * b
        b = b.divide(b);  // b = b / b
        b = b.remainder(b); // b = b % b
        b = b.pow(n);  // b ^ n
        if (ans.compareTo(b) == 0) { // 比较两个大数
            System.out.println("equ");
        }
        // 二维
        BigInteger c[][] = new BigInteger[110][110];
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                c[i][j] = BigInteger.valueOf(0); // 别忘了初始化
        String s = b.toString(k); // 大数转化成k进制的字符串
        System.out.println(s.charAt(0)); // s[0]
        char[] ch = s.toCharArray(); // String转化成char数组
        for (int i = 0; i < ch.length; i++) {
            System.out.println(ch[i]);
        }

    }
}
}
