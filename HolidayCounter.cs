using System;

namespace HolidayCounter
{
    class Program
    {
        public static int DaysUntil(DateTime srt, DateTime end)
        {
            var days = (end - srt).TotalDays;
            if (days < 0)
            {
                days = 365 + days;
            }
            return (int)days + 1;
        }

        static void Main(string[] args)
        {

            DateTime now = DateTime.Now;
            int y = now.Year;

            DateTime newYears = new DateTime(y, 1, 1);
            DateTime vDay = new DateTime(y, 2, 14);
            DateTime halloween = new DateTime(y, 10, 31);
            DateTime xMas = new DateTime(y, 12, 25);

            Console.WriteLine("Today is " + now.ToString("MMMM d yyyy") + "\n");

            Console.WriteLine(DaysUntil(now, newYears) + " days until New Years");
            Console.WriteLine(DaysUntil(now, vDay) + " days until Valentines Day");
            Console.WriteLine(DaysUntil(now, halloween) + " days until Halloween");
            Console.WriteLine(DaysUntil(now, xMas) + " days until Christmas");
        }
    }
}
