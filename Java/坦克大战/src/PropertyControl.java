import java.io.IOException;
import java.util.Properties;

public class PropertyControl {
    static Properties props = new Properties();
    static {
        try {
            props.load(PropertyControl.class.getClassLoader().getResourceAsStream("config/tanks.properties"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private PropertyControl(){};
    public static String getProperty(String key) {
        return props.getProperty(key);
    }
}
