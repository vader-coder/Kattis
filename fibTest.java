import java.util.*;
import java.lang.*;
import java.io.*;
import fibonnaci.java;//will have to change for githhub.
import java.util.concurrent.TimeUnit;

//Long, String, Int
//System.out.println();
class fibTest {
    public static void print(String str) {
        System.out.println(str);
    }
    public static String str(long l) {
        return Long.toString(l);
    }
	public static void main (String[] args) {
	    Solution soln = new Solution();
        Queue<long> dynamicAns = new LinkedList<long>();
        Queue<long> recursiveAns = new LinkedList<long>();
        Queue<Pair<long, long>>> timePair = new LinkedList<Pair<long, long>>>();
        long rEnd, dStart, dEnd;
        for (int i=0; i<args.size(); i++) {
            int input = Long.parseInt(args[i]);
            dStart = Instant.now();
            dynamicAns.add(soln.dynamicFibonacci(input));
            dEnd = Instant.now();
            recursiveAns.add(soln.recursiveFibonacci(input));
            rEnd = Instant.now();
            long dTime = Duration.between(dStart, dEnd).toMillis();
            long rTime = Duration.between(dEnd, rEnd).toMillis();
            timePair.add(new Pair<long><long>(dTime, rTime));
        }
        String[] out = {"Dynamic: ", " in ", " milliseconds"}
        while (!dynamicAns.isEmpty()) {
            Pair<long, long> time = timePair.remove();
            String dynamicOutput = out[0] + str(dynamicAns.remove()) + out[1] + str(time.first) + out[3];
            String recursiveOutput = out[0] + str(recursiveAns.remove()) + out[1] + str(time.second) + out[3];
            print(dynamicOutput);
            print(staticOutput);
        }
    }
}