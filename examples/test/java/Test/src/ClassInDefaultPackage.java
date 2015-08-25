


public class ClassInDefaultPackage {

    private final int i;

    public ClassInDefaultPackage(int i) {
        this.i = i;
        System.out.println("java constructor for Main("+i+") called.");
    }
    
    public static void staticTest(int i) {
	System.out.println("java Main.staticTest("+i+") called.");
    }
    
    public int getI() {
        System.out.println("java Main.getI() returning:"+i);
        return i;
    }
}
