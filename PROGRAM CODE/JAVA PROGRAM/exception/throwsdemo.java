class throwsdemo
{
        static void check()
        {
                try
                {
                        throw new NullPointerException("love sex or dhoka");

                }
                catch(NullPointerException e)
                {
                        System.out.println("caught inside check");
                        throw e;
                }
        }
        public static void main(String args[])
        {
                try
                {
                        check();
                }
                catch(NullPointerException e)
                {
                        System.out.println("recaught:" +e);
                }
        }
}
                        
                        

