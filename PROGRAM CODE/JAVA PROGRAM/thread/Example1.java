public class Example1 implements Runnable
{
   int count=0;
   public void run()
   {
      for(int i=0;i<5;i++)
       System.out.println(Thread.currentThread().getName()+":"+count++);
   }
 public static void main(String args[])throws InterruptedException
 {
   int count1=0;
   System.out.println("Main Thread: creating 2 child Thread");
   Example1 e1=new Example1();
   Example1 e2=new Example1();
   Thread t1=new Thread(e1);
   Thread t2=new Thread(e2);
   System.out.println("Main: 2 child thread are born");
   t1.start();
   t2.start();
   System.out.println("Main 2 child thread are ready");
   for(int i=0;i<5;i++)
   System.out.println("MainThread: "+count1++);
   t1.join();
   t2.join();
   System.out.println("Main Thread Ending");
   }
  }
