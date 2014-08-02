using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace DreamNet.TCPServer
{
    class Program
    {
        public static void Main()
        {
            //TestTCPServer1();
            TestTCPServer2();
        }

        static int GetBigEndianIntegerFromByteArray(byte[] data, int startIndex)
        {
            return (data[startIndex] << 24)
                 | (data[startIndex + 1] << 16)
                 | (data[startIndex + 2] << 8)
                 | data[startIndex + 3];
        }

        static int GetLittleEndianIntegerFromByteArray(byte[] data, int startIndex)
        {
            return (data[startIndex + 3] << 24)
                 | (data[startIndex + 2] << 16)
                 | (data[startIndex + 1] << 8)
                 | data[startIndex];
        }

        #region TCPServer 02
        static void TestTCPServer2()
        {
            while (true)
            {
                TcpListener server = null;
                try
                {
                    // Set the TcpListener on port 13000.
                    Int32 port = 13000;
                    IPAddress localAddr = IPAddress.Parse("127.0.0.1");

                    // TcpListener server = new TcpListener(port);
                    server = new TcpListener(localAddr, port);

                    // Start listening for client requests.
                    server.Start();

                    // Buffer for reading data
                    Byte[] bytes = new Byte[256];
                    String data = null;

                    // Enter the listening loop. 
                    while (true)
                    {
                        Console.Write("Server: Waiting for a connection... ");

                        // Perform a blocking call to accept requests. 
                        // You could also user server.AcceptSocket() here.
                        TcpClient client = server.AcceptTcpClient();
                        Console.WriteLine("Connected!");

                        data = null;

                        // Get a stream object for reading and writing
                        int i = 0;
                        using (NetworkStream stream = client.GetStream())
                        {
                            while (client.Connected)
                            {
                                i = stream.Read(bytes, 0, bytes.Length);
                                data = System.Text.Encoding.ASCII.GetString(bytes, 0, bytes.Length);


                                int iValor = BitConverter.ToInt32(bytes, 0);            // OK
                                double dValor = BitConverter.ToDouble(bytes, 4);        // OK

                                Console.WriteLine("Received: {0} | {1} | {2}", i, iValor, dValor);


                                for (int j = 0; j < 10; j++ )
                                {
                                     Console.WriteLine("Received: {0} | {1}", j, BitConverter.ToDouble(bytes, j));
                                }

                                    stream.Write(bytes, 0, 256);
                                Console.WriteLine("Sent: {0}", data);


                                // Translate data bytes to a ASCII string.
                                //data = System.Text.Encoding.ASCII.GetString(bytes, 0, sizeof(int));
                                //data = System.Text.Encoding.UTF32.GetBytes(bytes, 0, sizeof(int));
                                //Console.WriteLine("Received ({0}): {1} | {2}", i, data, BitConverter.ToInt32(bytes, 0));
                                /*
                                int number = bReader.ReadInt32();
                                Console.WriteLine("Received: {0} | {1}", number);
                                */
                                /*
                                Encoding.UTF32.get

                                // Translate data bytes to a ASCII string.
                                data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);
                                Console.WriteLine("Received: {0}", data);

                                // Process the data sent by the client.
                                data = data.ToUpper();

                                byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);

                                // Send back a response.
                                stream.Write(msg, 0, msg.Length);
                                Console.WriteLine("Sent: {0}", data);
                                */
                            }
                        }


                        //client.Close();
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Exception: {0}", e);
                }
                finally
                {
                    // Stop listening for new clients.
                    server.Stop();
                }


                Console.WriteLine("\nHit enter to continue...");
            }
        }
        #endregion

        #region TCPServer 01
        static void TestTCPServer1()
        {
            while (true)
            {
                TcpListener server = null;
                try
                {
                    // Set the TcpListener on port 13000.
                    Int32 port = 13000;
                    IPAddress localAddr = IPAddress.Parse("127.0.0.1");

                    // TcpListener server = new TcpListener(port);
                    server = new TcpListener(localAddr, port);

                    // Start listening for client requests.
                    server.Start();

                    // Buffer for reading data
                    Byte[] bytes = new Byte[256];
                    String data = null;

                    // Enter the listening loop. 
                    while (true)
                    {
                        Console.Write("Server: Waiting for a connection... ");

                        // Perform a blocking call to accept requests. 
                        // You could also user server.AcceptSocket() here.
                        TcpClient client = server.AcceptTcpClient();
                        Console.WriteLine("Connected!");

                        data = null;

                        // Get a stream object for reading and writing
                        int i = 0;
                        using (NetworkStream stream = client.GetStream())
                        {
                            while (client.Connected && (i = stream.Read(bytes, 0, bytes.Length)) != 0)
                            {

                                // Translate data bytes to a ASCII string.
                                data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);
                                Console.WriteLine("Received: {0}", data);

                                // Process the data sent by the client.
                                data = data.ToUpper();

                                byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);

                                // Send back a response.
                                stream.Write(msg, 0, msg.Length);
                                Console.WriteLine("Sent: {0}", data);

                            }
                        }


                        client.Close();
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Exception: {0}", e);
                }
                finally
                {
                    // Stop listening for new clients.
                    server.Stop();
                }


                Console.WriteLine("\nHit enter to continue...");
            }
        }
        #endregion
    }   

}
