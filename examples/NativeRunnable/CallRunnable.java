public class CallRunnable {
   public void call(Runnable r) {
       try {
           System.out.println("CallRunnable.java calling Runnable r=" + r);
           r.run();
           System.out.println("CallRunnable.java : Runnable returned.");
       } catch (Exception e) {
           e.printStackTrace();
       }
   }
}
