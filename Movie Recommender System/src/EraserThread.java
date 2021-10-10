public class EraserThread extends Thread {
    private boolean stop;
    public void run()
    {
        stop = true;
        int i = 0;
        while (stop)
        {
           /* if (i == 0)
            {
                System.out.print("\010 ");
                i++;
            }*/
            //else
            {
                System.out.print("\010*");
                i++;
            }
            try
            {
                Thread.currentThread().sleep(1);
            }
            catch(InterruptedException ie)
            {
                ie.printStackTrace();
            }
        }
    }
    void stopMasking()
    {
        this.stop = false;
    }
}
