public class Example extends Thread
{
   int count=0;
   public void run()
   {
      for(int i=0;i<5;i++)
       System.out.println(this.getName()+":"+count++);
   }
 public static void main(String args[])throws InterruptedException
 {
   int count1=0;
   System.out.println("Main Thread: creating 2 child Thread");
   Example e1=new Example();
   Example e2=new Example();
   System.out.println("Main: 2 child thread are born");
   e1.start();
   e2.start();
   System.out.println("Main 2 child thread are ready");
   for(int i=0;i<5;i++)
   System.out.println("MainThread: "+count1++);
   e1.join();
   e2.join();
   System.out.println("Main Thread Ending");
   }
  }
