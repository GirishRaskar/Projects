import java.util.*;
import java.io.*;

class PackerUnpackerCUI
{
    public static void main(String Arg[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("\n-----------------------------------------------------");
        System.out.println("------- Marvellous Packer Unpacker CUI Module -------");
        System.out.println("-----------------------------------------------------");

        System.out.println("Enter the Activity");
        System.out.println("1.Packing\n2.Unpacking");
        int iChoice = sobj.nextInt();
        sobj.nextLine();

        switch(iChoice)
        {
            case 1:
            System.out.println("\n\n----------------- Packing Activity ------------------");
            System.out.println();

            System.out.println("Enter the name of Directory that you want to open for packing : ");
            String FolderName = sobj.nextLine();

            File fobj = new File(FolderName);

            System.out.println("\nEnter the name of packed file that you want to create : ");
            String PackedFile = sobj.nextLine();
            System.out.println();

            File Packobj = new File(PackedFile);
            
            boolean bret = Packobj.createNewFile();
            if(bret == false)
            {
                System.out.println("Unable to create packed file");
                return;
            }

            FileOutputStream foobj = new FileOutputStream(Packobj);

            if(fobj.exists())
            {
                int i = 0, j = 0;
                int iCount = 0;

                File Arr[] = fobj.listFiles();

                
                String Header = null;
                int iRet = 0;
                byte Buffer[] = new byte[1024];
                FileInputStream fiobj = null;
                
                for(i = 0; i < Arr.length; i++)
                {
                    Header = Arr[i].getName();
                    
                    if(Header.endsWith(".txt"))
                    {
                        System.out.println("File packed with name : "+Header);
                        
                        Header = Header + " " + Arr[i].length();

                        for(j = Header.length(); j < 100; j++)
                        {
                            Header = Header + " ";
                        }

                        foobj.write(Header.getBytes(),0,100);

                        fiobj = new FileInputStream(Arr[i]);

                        while((iRet = fiobj.read(Buffer))!= -1)
                        {
                            foobj.write(Buffer,0,iRet);
                        }

                        fiobj.close();
                        iCount++;
                    }
                }

                System.out.println("\n-----------------------------------------------------");
                System.out.println("Packing activity completed..");
                System.out.println("Number of files scan : "+Arr.length);
                System.out.println("Number of files packed : "+iCount);
                System.out.println("-----------------------------------------------------");

                System.out.println("\nThank you for using Marvellous Packer Unpacker tool\n");
                foobj.close();
            }
            else
            {
                System.out.println("There is no such directory");
            }
            break;

            case 2:
            byte Header[] = new byte[100];
            int iRet = 0;
            String HeaderX = null;
            File obj = null;
            int FileSize = 0;
            FileOutputStream foobj1 = null;
            int iCount = 0;

            System.out.println("\n\n---------------- Unpacking Activity -----------------");
            System.out.println();

            System.out.println("Enter the name of Packed file that you want to open : ");
            String PackFile = sobj.nextLine();
            System.out.println();

            File fobj1 = new File(PackFile);

            if(!fobj1.exists())
            {
                System.out.println("Unable to proceed as Packed file is missing...");
                return;
            }  

            FileInputStream fiobj = new FileInputStream(fobj1);

            while((iRet = fiobj.read(Header,0,100)) > 0)
            {
                HeaderX = new String(Header);
                HeaderX = HeaderX.trim();

                String Tokens[] = HeaderX.split(" ");

                obj = new File(Tokens[0]);
                System.out.println("File drop with name : "+Tokens[0]);

                obj.createNewFile();

                FileSize = Integer.parseInt(Tokens[1]);
                byte Buffer[] = new byte[FileSize];

                fiobj.read(Buffer,0,FileSize);

                foobj1 = new FileOutputStream(obj);
                foobj1.write(Buffer,0,FileSize);

                foobj1.close();
                iCount++;
            }

            System.out.println("\n-----------------------------------------------------");
            System.out.println("Unpacking activity completed..");
            System.out.println("Number of files unpacked : "+iCount);
            System.out.println("-----------------------------------------------------");

            System.out.println("\nThank you for using Marvellous Packer Unpacker tool\n");
            
            fiobj.close();
        }
    }
}