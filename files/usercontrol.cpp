#include "usercontrol.h"
using namespace vex;

void motorTestControl() {
    // 电机控制示例代码，仅作参考
    if(R1) {
        moveTestMotor(100);
    }
    else{
        moveTestMotor(0);
    }
}

void allDeviceControl() {
    // 在这里添加对所有设备的控制代码
    // 例如，控制电机、传感器等
    motorTestControl();
}

void userControl() {
    // 用户控制代码
    while (true) {
        allDeviceControl();
        this_thread::sleep_for(2); // 避免占用过多CPU资源
    }
}