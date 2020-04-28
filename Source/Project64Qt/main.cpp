#include <iostream>

//Test for fun
#include "Common/Random.h"

//From Windows main
#include "Project64-core/AppInit.h"
//#include "Multilanguage\LanguageSelector.h"
//#include "Settings/UISettings.h"
#include "Common/path.h"

int main(int argc, const char** argv)
{
    CRandom random;
    std::cout << "Hello World! " << random.next() << std::endl;
    //CNotification notify;
    //AppInit(&notify, CPath(CPath::DIR_CURRENT_DIRECTORY), argc, argv);
}
