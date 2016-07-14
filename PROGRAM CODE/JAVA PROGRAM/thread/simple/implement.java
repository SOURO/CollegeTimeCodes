class t implements Runnable
{
        public void run()
        {
                System.out.println("t is running by" +Thread.currentThread().getName());
        }
}
public class implement
{
        public static void main(String args[])
        {
                t ob=new t();
                Thread t1=new Thread(ob);
                //t1.Setname("soura");
                t1.start();
        }
}
