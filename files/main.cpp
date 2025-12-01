#include "main.h"

using namespace vex;

competition Competition;

int main() {
    thread Tcontroller(defineController);

    Competition.drivercontrol(userControl);

    while (true) {
        // 运行其他线程
        this_thread::sleep_for(2);
    }
}