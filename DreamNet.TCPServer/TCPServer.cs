using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace DreamNet.TCPServer
{
    public class TCPServer
    {
        #region Variables
        private TcpListener server = null;
        private TcpClient client = null;
        private int bufferSize = 64;
        
        #endregion

        public TCPServer(string _address, int _port)
        {
            IPAddress address = IPAddress.Parse(_address);
            Int32 port = _port;
            this.server = new TcpListener(address, port);
        }

        public void Open()
        {
            server.Start();
        }

        public void ListenForClients()
        {
            Console.Write("Server: Waiting for a connection... ");
            client = server.AcceptTcpClient();
            Console.WriteLine("Connected!");
        }

        public void HandleClientComm()
        {
            using (NetworkStream stream = client.GetStream())
            {
                while (client.Connected)
                {
                    Send(stream);
                    Receive(stream);
                }
            }
        }
       
        protected void Send(NetworkStream stream)
        {
            Byte[] bytesRead = new Byte[bufferSize];
            // Leitura dos dados na rede
            stream.Read(bytesRead, 0, bufferSize);

            // Pega os dados do robo
            robotStatus = BitConverter.ToInt32(bytesRead, 0);
            robotPosition = BitConverter.ToDouble(bytesRead, 4);

            Console.Clear();
            Console.WriteLine("ROBOT #######################\n");
            Console.WriteLine("Status: {0}", robotStatus);
            Console.WriteLine("Position: {0}\n", robotPosition);
            Console.WriteLine("Bytes (Receive): " + BitConverter.ToString(bytesRead) + "\n");
        }

        protected void Receive(NetworkStream stream)
        {
            Byte[] bytesWrite = new Byte[bufferSize];

            // Dados do robo
            gamePosition += 1.5;
            gameStiffness += 2.0;
            gameVelocity += 3.0;
            gameAcceleration += 5.0;
            gameControl++;

            // Escrevendo os dados na rede         

            Array.Copy(BitConverter.GetBytes(gameControl), 0, bytesWrite, 0, sizeof(int));
            Array.Copy(BitConverter.GetBytes(gamePosition), 0, bytesWrite, 4, sizeof(double));
            Array.Copy(BitConverter.GetBytes(gameStiffness), 0, bytesWrite, 12, sizeof(double));
            Array.Copy(BitConverter.GetBytes(gameVelocity), 0, bytesWrite, 20, sizeof(double));
            Array.Copy(BitConverter.GetBytes(gameAcceleration), 0, bytesWrite, 28, sizeof(double));

            stream.Write(bytesWrite, 0, bufferSize);

            Console.WriteLine("\nGAME ########################\n");
            Console.WriteLine("Position: {0}", gamePosition);
            Console.WriteLine("Stiffness: {0}", gameStiffness);
            Console.WriteLine("Velocity: {0}", gameVelocity);
            Console.WriteLine("Acceleration: {0}", gameAcceleration);
            Console.WriteLine("Control: {0}", gameControl);
            Console.WriteLine("Bytes (Send): " + BitConverter.ToString(bytesWrite) + "\n");
        }


        // Variáveis
        double gamePosition;
        double gameStiffness;
        double gameVelocity;
        double gameAcceleration;
        int gameControl;
        int robotStatus;
        double robotPosition;
    }
}


/*

        #region Events

        public event EventHandler<ServerEventArgs> OnConnect;
        public event EventHandler<ServerEventArgs> OnReceive;
        public event EventHandler<ServerEventArgs> OnDisconnect;
        public event EventHandler<ServerEventArgs> OnStarted;
        public event EventHandler<ServerEventArgs> OnStopped;

        #endregion

*/