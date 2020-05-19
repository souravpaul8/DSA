import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    static BigInteger fact(int N){
            BigInteger b = new BigInteger("1");
            
            for(int i=2;i<=N;i++){
                b = b.multiply(BigInteger.valueOf(i));
            }
            return b;
        
    }

    
    static void playWithInt(){
        
        Scanner sc = new Scanner(System.in);
        
        int s1 = sc.nextInt();
        System.out.println(s1*s1);
        
        BigInteger one = new BigInteger("4"); // Create BigInteger object whose value is 1 
        BigInteger two = new BigInteger("123456789101010");
        
        System.out.println(two.add(one));
        
        //Read a string as a big Integer
        String s2 = sc.next();
        String s3 = sc.next();
        
        BigInteger three = new BigInteger(s2,2);
        BigInteger b4 = new BigInteger(s3,2);
        
        three = three.multiply(b4);
        three = three.add(two);
        three = three.divide(two);
        
        System.out.println(three);
        
        //Computing GCD
        BigInteger b0 = new BigInteger("20");
        //Valueof methods converts long int into your int
        BigInteger b1 = BigInteger.valueOf(12);
        
        System.out.println( b1.gcd(b0));
        
        // 9 * 4  = 36
        //Next Probable Primt - Automatically generates your next prime Number
        System.out.println(b0.nextProbablePrime());
        
        //Bitwise 
        //Count of the set of Bits 
        System.out.println(b1.bitCount());
        
        
    }

    public static void main(String args[]) {
         playWithInt();

        //BigInteger b = sc.nextBigInteger();
        System.out.println(fact(1000));
    }
}