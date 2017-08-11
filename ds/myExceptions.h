#ifndef myExceptions_
#define myExceptions_
#include <string>

using namespace std;

class illegalParameterValue {
    string message;
public:
    illegalParameterValue(string theMessage = "illegal parameter value") {
        message = theMessage;
    }
    void outputMessage() {cout << message << endl;}
};

#endif
