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
            TCPServer server = new TCPServer("127.0.0.1", 13000);
            server.Open();
            server.ListenForClients();
            server.HandleClientComm();
        }

        #region STATIC METHODS
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


                                for (int j = 0; j < 10; j++)
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

        #region TCPServer 03
        static void TestTCPServer3()
        {
            const int BUFFER_SIZE = 64;

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
                    Byte[] bytesRead = new Byte[BUFFER_SIZE];
                    Byte[] bytesWrite = new Byte[BUFFER_SIZE];

                    // Enter the listening loop. 
                    while (true)
                    {
                        Console.Write("Server: Waiting for a connection... ");

                        // Perform a blocking call to accept requests. 
                        // You could also user server.AcceptSocket() here.
                        TcpClient client = server.AcceptTcpClient();
                        Console.WriteLine("Connected!");

                        // Get a stream object for reading and writing
                        int i = 0;
                        int cont = 1;
                        using (NetworkStream stream = client.GetStream())
                        {
                            while (client.Connected)
                            {
                                // Leitura dos dados na rede
                                i = stream.Read(bytesRead, 0, BUFFER_SIZE);

                                // Pega os dados do robo
                                int robotStatus = BitConverter.ToInt32(bytesRead, 0);
                                double robotPosition = BitConverter.ToDouble(bytesRead, 4);

                                Console.Clear();
                                Console.WriteLine("ROBOT #######################\n");
                                Console.WriteLine("Status: {0}", robotStatus);
                                Console.WriteLine("Position: {0}\n", robotPosition);

                                // Dados do robo
                                double gamePosition = cont * 1.5;
                                double gameStiffness = cont * 2.0;
                                double gameVelocity = cont * 3.0;
                                double gameAcceleration = cont * 5.0;
                                int gameControl = cont;

                                // Escrevendo os dados na rede         

                                Array.Copy(BitConverter.GetBytes(gameControl), 0, bytesWrite, 0, sizeof(int));
                                Array.Copy(BitConverter.GetBytes(gamePosition), 0, bytesWrite, 4, sizeof(double));
                                Array.Copy(BitConverter.GetBytes(gameStiffness), 0, bytesWrite, 12, sizeof(double));
                                Array.Copy(BitConverter.GetBytes(gameVelocity), 0, bytesWrite, 20, sizeof(double));
                                Array.Copy(BitConverter.GetBytes(gameAcceleration), 0, bytesWrite, 28, sizeof(double));


                                stream.Write(bytesWrite, 0, BUFFER_SIZE);

                                Console.WriteLine("\nGAME ########################\n");
                                Console.WriteLine("Position: {0}", gamePosition);
                                Console.WriteLine("Stiffness: {0}", gameStiffness);
                                Console.WriteLine("Velocity: {0}", gameVelocity);
                                Console.WriteLine("Acceleration: {0}", gameAcceleration);
                                Console.WriteLine("Control: {0}", gameControl);

                                //printf("Tempo %.3f (ms)\n", ((double)(stop - start) / CLOCKS_PER_SEC));

                                Console.WriteLine("Bytes (Receive): "  + BitConverter.ToString( bytesRead )  + "\n");
                                Console.WriteLine("Bytes (Send): " + BitConverter.ToString( bytesWrite ) + "\n");

                                cont++;
                            }
                        }
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
