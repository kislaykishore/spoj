import java.util.*;
public class Shpath {
    public static void main(String [] args) throws Exception {
        try(InputStreamReader is = new InputStreamReader(System.in);
            BufferedReader buf = new BufferedReader(is)) {
            int test = Integer.parseInt(buf.readLine().trim());
            while(test-- != 0) {
                int cities = Integer.parseInt(buf.readLine().trim());
                Map<Integer, String>cityIndexMap = new HashMap<>();
                Map<String, Integer>indexCityMap = new HashMap<>();
                for(int i=1;i<=cities;++i) {
                    String name = buf.readLine().trim();
                    cityIndexMap.put(i, name);
                    indexCityMap.put(name, i);

                    int neighbors = Integer.parseInt(buf.readLine().trim());
                    for(int j=0;j<neighbors;++i) {
                        
                    }
                }
            }
        }
    }
}
