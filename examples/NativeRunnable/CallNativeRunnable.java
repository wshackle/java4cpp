

public class CallNativeRunnable {
   public void call(NativeRunnable r) {
       try {
           System.out.println("CallNativeRunnable.java calling Runnable r=" + r);
           r.run();
           System.out.println("CallNativeRunnable.java : Runnable returned.");
       } catch (Exception e) {
           e.printStackTrace();
       }
   }
   
    public static void main(String[] args) {
        try(NativeRunnable nr = new NativeRunnable()) {
            new CallNativeRunnable().call(nr);
        }
    }
}
