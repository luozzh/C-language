#include "emis.h"

int main(int argc,const char* argv[])
{
	Emis& emis = Emis::getEmis();
	emis.start();
}
