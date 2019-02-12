using System;
using System.Drawing;
using System.Diagnostics;
using System.IO.Ports;

namespace ImagePharser
{
    class Program
    {
        static void Main(string[] args)
        {
            string output = "";
            Bitmap img = new Bitmap("#");
            for(int x=0;x<img.Width;x++)
            {
                for(int y=0;y<img.Height;y++)
                {
                    Color pixel = img.GetPixel(x, y);
                    if(pixel.ToArgb().Equals(Color.Black.ToArgb()))
                    {
                        output = output + "1";
                    }
                    else
                    {
                        output = output + "0";
                    }
                }
                output = output + ",";
            }
            SerialPort serial = new SerialPort("COM8", 9600);
            serial.Open();
            serial.Write(output);
            serial.Close();
            Debug.WriteLine(output);
        }
    }
}
