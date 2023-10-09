# include <Functions.hpp>
void EncryptStringCesarus (string &ToEncrypt, signed int Key)
{

    	for (char &Character : ToEncrypt)
      	{
		if ((int(Character)+Key) > 122)
		{
			unsigned int Offset{int(Character)+Key-122};
			Character=char(97 + Offset)
		}
		else
		{
			Character += Key;
		}
      	}
}

void EncryptASCII(string &ToEncrypt, signed int Key)
{
	for (char &Character : ToEncrypt)
	{
		Character += Key;
	}
}

void EncryptStringVigener(string &ToEncrypt, signed int Key)
{
	return;
}

void GetFile(string FileName)
{
	std::ifstream File (FileName, std::ios_base::out | std::ios_base::app);
        if (!File.is_open())
        {
                std::cout << "Error opening original file\n";
                return;
        }
        //std::cout << File.rdbuf() << '\n';
        FileName = 'e' + FileName;
        std::fstream eFile (FileName, std::ios_base::app | std::ios_base::in | std::ios_base::out);
        if (eFile.is_open())
        {
                //std::cout << "Sucksess\n";
        }
        string Buffer{};
        while(getline(File, Buffer))
        {
                std::cout << Buffer << '\n';
                EncryptStringCesarus(Buffer, 1);
                eFile << Buffer;
        }
        eFile.close();
	File.close();

}


void DecryptCesarus(string& EncryptedString, signed int Key)
{
	for (char &Character : EncryptedString)
	{
                if ((int(Character)+Key) < 97)
                {
                        unsigned int Offset{97 - int(Character)+Key};
                        Character=char(122 - Offset)
                }
                else
                {
                        Character -= Key;
                }
        }

}

void DecryptASCII(string& EncryptedString, signed int Key)
{
	for (char &Character : ToEncrypt)
        {
                Character -= Key;
        }

}

