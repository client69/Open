import java.util.*;
import java.util.Random;
/**
 * Write a description of class RandomN here.
 *
 * @author (Simon Bech)
 * @version (1.0)
 */
public class RandomN
{
    Random gen;
    int index = 0;
    public RandomN(){
        gen = new Random();
        this.gen = gen;
    }

    public void printOneRandom(){
        int index = gen.nextInt(100);
        System.out.println(index);
    }
}
