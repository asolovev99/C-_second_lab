using System;
using System.Net;
using System.IO;
using Newtonsoft.Json;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            WebRequest request = WebRequest.Create("http://api.openweathermap.org/data/2.5/weather?q=Novosibirsk&appid=2622881ef44d9b887fc17b6732898e25");
            WebResponse response = request.GetResponse();

            using (Stream dataStream = response.GetResponseStream())
            {
                // Open the stream using a StreamReader for easy access.
                StreamReader reader = new StreamReader(dataStream);
                // Read the content.
                string responseFromServer = reader.ReadToEnd();
                // Display the content.
                //Console.WriteLine(responseFromServer);

                string json = JsonConvert.SerializeObject(reader, Formatting.Indented);

                //Console.WriteLine(json);
            }

            

            // Close the response.
            response.Close();
        }
    }
}

