# include <>
# include <assert.h>
void Tests()
{
	assert(EncryptStringCesarus("abc", 1) == "bcd");
	//assert(EncryptStringVigener("abc", 1) == "bdf");
	assert(EncryptASCII("abc", 10) == "klm");
}
