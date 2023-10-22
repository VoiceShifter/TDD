# include <assert.h>
# include <iostream>
# include <string>


using std::string;

void EncryptStringCesarus (string &ToEncrypt, signed int Key)
{

        for (char &Character : ToEncrypt)
        {
                if ((int(Character)+Key) > 122)
                {
                        unsigned int Offset{int(Character)+Key-123};
                        Character=char(97 + Offset);
                }
                else
                {
                        Character += Key;
                }
        }
};

void EncryptASCII(string &ToEncrypt, signed int Key)
{
        for (char &Character : ToEncrypt)
        {
                Character += Key;
        }
};

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

void Tests()
{
        std::string Test{"xyz"};
        EncryptStringCesarus(Test, 1);
        std::cout << Test << '\n';
        assert(Test== "yza");
        //assert(EncryptStringVigener("abc", 1) == "bdf");
        Test="xyz";
        EncryptASCII(Test, 1);
        std::cout << Test << '\n';
        assert(Test== "yz{");
};



signed int main()
{
	Tests();
	return 0;	
}



