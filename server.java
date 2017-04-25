import java.io.*;
import java.net.*;

	class server
	{
		public static void main(String argv[]) throws Exception
		{
			String clientSentence;
			String capitalizedSentence;
			ServerSocket welcomeSocket = new ServerSocket(5000);
			System.out.println("Waiting Message From Client");

				while(true)
				{
					Socket connectionSocket = welcomeSocket.accept();

					BufferedReader clientInput =
					new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));

					DataOutputStream clientOutput = new DataOutputStream(connectionSocket.getOutputStream());
								
					clientSentence = clientInput.readLine();

					System.out.println("Client : " + clientSentence);
								
					capitalizedSentence = new StringBuilder(clientSentence).reverse().toString() + '\n';
								
					clientOutput.writeBytes(capitalizedSentence);
				}
		}
	}
