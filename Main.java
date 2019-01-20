import java.util.*;
import java.lang.*;
import java.math.BigInteger;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
            try(InputStreamReader is = new InputStreamReader(System.in);
                BufferedReader buf = new BufferedReader(is)) {
                BigInteger num = new BigInteger(buf.readLine());
                BigInteger exp = new BigInteger(buf.readLine());
                BigInteger val = num.modPow(exp, BigInteger.valueOf(9));
                int op = (9 + val.intValue()) % 9;
                op = op == 0 && !num.equals(BigInteger.ZERO)?9:op;
                System.out.println(op);
            }
	}
}
