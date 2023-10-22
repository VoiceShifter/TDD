# include <iostream>
# include <fstream>
# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <vector>
# include <array>
# include <stdexcept>
# include <memory>
# include <sstream>
# include <iterator>

using std::string;



enum Type
{
        ASCII,
        Cesarus,
	dASCII,
	dCesarus
};




void EncryptStringCesarus (string &, signed int);
void EncryptStringVigener (string &, signed int);
void EncryptASCII(string &, signed int);
void GetFile(string, Type);
void DecryptCesarus(string &, signed int);
void DecryptASCII(string &, signed int);
std::string exec(const char* cmd);


void EncryptStringCesarus (string &ToEncrypt, signed int Key)
{

    	for (char &Character : ToEncrypt)
      	{
		if ((int(Character)+Key) > 122)
		{
			unsigned int Offset{int(Character)+Key-122};
			Character=char(97 + Offset);
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


void GetFile(string FileName, Type Enc = Cesarus)
{

	std::ifstream File (FileName, std::ios_base::out | std::ios_base::app);
        if (!File.is_open())
        {
                std::cout << "Error opening original file -  " << FileName << " probably executable"<<'\n';
                return;
        }
        //std::cout << File.rdbuf() << '\n';
	FileName = 'e' + FileName;		
      	std::fstream eFile (FileName, std::ios_base::app | std::ios_base::in | std::ios_base::out);
       


        string Buffer{};
        while(getline(File, Buffer))
        {
		switch(Enc)
		{
			case Cesarus:
			       	EncryptStringCesarus(Buffer, 1);
			       	break;
			case ASCII:
			       	EncryptASCII(Buffer, 10);
			       	break;
			case dASCII:
				DecryptASCII(Buffer, 10);
				break;

			case dCesarus:
				DecryptCesarus(Buffer, 1);
				break;

			default: return;
		}	
               
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
                        Character=char(123 - Offset);
                }
                else
                {
                        Character -= Key;
                }
        }

}

void DecryptASCII(string& EncryptedString, signed int Key)
{
	for (char &Character : EncryptedString)
        {
                Character -= Key;
        }

}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}


signed int main()
{
	
	std::cout << "Options:\n1 - Incrypt Cesarus\n" << "2 - Decrypt Cesarus\n" << "3 - Incrypt ASCII\n" << "4 - Decrypt ASCII\n";
	signed int Choose{};
	Type ChoosedEnc{};
	std::cin >> Choose;
	if (!std::cin)
	{
		std::cout <<"Wrong option\n";
	}
	switch(Choose)
	{
		case 1:

			ChoosedEnc = Cesarus;
			break;
		case 2:

			ChoosedEnc = dCesarus;
			break;
		case 3:

			ChoosedEnc = ASCII;
			break;
		case 4:

			ChoosedEnc = dASCII;
			break;
		default:
			std::cout <<"Typo\n";
			break;

	}
	std::vector<string> AllFiles;
	string Container(exec("ls"));
	string aTest{};
	std::istringstream Container2{Container};
	while(std::getline(Container2, aTest, '\n'))
	{
		AllFiles.push_back(aTest);
	}
	
	for (auto File: AllFiles)
	{
		GetFile(File, ChoosedEnc);	
	}








	
	//string FileName{"test"};
	//GetFile(FileName);

}

