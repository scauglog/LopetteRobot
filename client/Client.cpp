#include <string>
#include <sstream>
#include "serialib.h"

using namespace std;


int main(){
    serialib port;
    port.Open("/dev/ttyUSB0", 115200);
    sleep(15);
    ostringstream oss;
    oss << 0x01 << 0x00 << 0x03 <<'a' << 'b' << 'c' << 0x44;
    port.WriteString(oss.str().c_str());
    char c;
    while(true){
        while (port.Read(&c, 1)<=0) {
            sleep(1);

        }
        cout << c << endl;
    }

}
