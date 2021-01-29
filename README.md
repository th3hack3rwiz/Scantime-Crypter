# Scantime-Crypter
The project aims at building a Scan-Time Crypter in C, that can assist a malware in bypassing antivirus software. The Crypter will open the malware from the disk while creating another output file to the disk. The Crypter will then extract the contents from the malware and obfuscate them using XOR encryption algorithm. The obfuscated contents will then be written to the previously created output file. When the obfuscated file is opened by the victim, the Crypter will then start the de-obfuscation process by using the same key it used to encrypt it in the first place. 

### The entire implementation of this project can be summarized in the following steps:

1. Creating a Malware: A windows meterpreter payload is crafted using msfvenom. Command used is - msfvenom –p     windows/meterpreter/reverse/tcp to create a reverse tcp meterpreter shell for windows 64bit OS. At the end of this step, an executable file called payload.exe will be created.

2. Encrypting the Malware using File Handling and XOR Encryption:

   **1.**   The file will be read using the function fopen() and mode ‘r’. 

   **2.**   The contents of the file will be retrieved using the fgets() function until it reachs EOF. 

   **3.**   The contents of the file will be XORed.

   **4.**   The encrypted contents will be then written to a new file and the stream will be closed to prevent data leakage.

3. Execution and Deobfuscation: The contents of the file will be deobfuscated when it is executed on the victim’s machine. Deobfuscation will be carried out using the same keys from encryption process.

4. Testing the Cryper: The Crypter will then be tested on services like [www.virustotal.com](http://www.virustotal.com/) and other antivirus software to prove the successful bypassing of Malware from security software.

 
#### ***Check out Implementation_Guide.docx for step by step procedure.***
 

### **ALGORITHM**

1. Define a macro XOR_VAR along with your key.
2. Create a character pointer buffer and initialize it to 0.

3. Create two strings for input file and output file.

4. Create a File Pointer fp.

5. Using fp, open the first argument (file) in rb (read-binary) mode.

6. Perform error handling to check if the file has opened successfully. 

7. If the file opened successfully, point fp to the last character using fseek function.

8. Create a variable length of type ‘long’ to store the position of the file pointer fp. 

9. Set the file pointer fp back to the start.

10. Dynamically allocate memory to buffer using malloc of size (length*size of no. of    characters).

11. Read the file using fp and store it in buffer one character at a time. 

12. Close the file pointer fp.

13. Pass buffer in the XORing function.

14. Define a function XORing which takes one-character pointer as argument.

    1. Start a for loop, create an integer i and iterate it according to the condition: for(int i=0;str[i]!='\0';i++). We’re iterating it until it reaches EOF.

    2. Perform binary XOR between character pointer and XOR_VAR macro.

15. Create a new file pointer fr.

16.Using fr, open the second argument (file) in wb (write-binary) mode.

17. Check if the file opened successfully using error handling.

18. Write the buffer to the file via fr (file pointer). 

19. Close the file pointer fr using fclose function. 

20. Clear the screen.

21. Run the second argument file (output file).


### CONCLUSION

- Obfuscating a malware using XOR encryption is better than other algorithms. When we XOR a piece of text, each character undergoes a bitwise operation. The encrypted piece of text can only be decrypted only by someone who has the key. To everyone else, the piece of text is just gibberish. This way, XOR Encryption takes the lead when compared to other algorithms like ROT13 or Base64 encoding. We see that the latter two do not need keys, hence can be easily decrypted and are less secure.

- The XOR encryption algorithm has a time complexity of O(n), which is the same as Base64 Encoding and ROT13, but the latter two have greater space complexities, and hence the encryption and decryption process becomes longer since the number of variables and the execution time is more. 

- In conclusion, the XOR Encryption algorithm is much more compact, reliable and efficient in comparison to other algorithms like Base64 Encoding and ROT13. 
