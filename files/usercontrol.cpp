#include "usercontrol.h"
// 新增
#include "robot_config.h" // 确保包含了电机定义
#include "controller.h" // 确保包含了手柄变量
#include "autonomous.h"
#include <iostream>
using namespace std;
using namespace vex;
#include <cmath>

void motorTestControl() {
    // 电机控制示例代码，仅作参考
    if(R1) {
        moveTestMotor(100);
    }
    else{
        moveTestMotor(0);
    }
}

// 新增
// 测试函数，按键可以替换，测试完成可将函数注释，不额外占用按键
//void testTurnTo() {
  //  if(press_A) {
   //     press_A = false;
   //     turnTo(90);
   // }
//}

//void testPIDDistanceForward() {
  //  if(press_B) {
   //     press_B = false;
  //      PIDDistanceForwardRel(60);
   // }
//}

//void testAuton() {
  //  if(press_X) {
   //     press_X = false;
  //      autonTest();
  //  }
//}

void allDeviceControl() {
    int speedMultiplier = 80;  // 默认全速
    if (X) {  // 按住X键时切换到慢速
        speedMultiplier = 40; 
        }
    // ========== 驱动控制 ==========
        // 读取由 controller.cpp 更新的全局变量
        int forwardVal = A3;  // 使用 A3 替代 Controller1.Axis3
        int turnVal    = A1;  // 使用 A1 替代 Controller1.Axis1

        // 设置"死区"——如果摇杆很小幅度抖动就当作 0
        if (abs(forwardVal) < 15) forwardVal = 0;
        if (abs(turnVal) < 15)    turnVal = 0;

        // 差速驱动组合：左右两边速度分别为 forward ± turn
        int leftSpeed  = forwardVal + turnVal;
        int rightSpeed = forwardVal - turnVal;

        // 限幅：防止超出有效范围 (这一部分逻辑保持不变)
        if (leftSpeed > 100)  leftSpeed = 100;
        if (leftSpeed < -100) leftSpeed = -100;
        if (rightSpeed > 100)  rightSpeed = 100;
        if (rightSpeed < -100) rightSpeed = -100;

        // 让四个驱动电机旋转
        LeftFrontMotor.spin(directionType::fwd, leftSpeed, velocityUnits::pct);
        LeftBackMotor.spin(directionType::fwd, leftSpeed, velocityUnits::pct);
        RightFrontMotor.spin(directionType::fwd, rightSpeed, velocityUnits::pct);
        RightBackMotor.spin(directionType::fwd, rightSpeed, velocityUnits::pct);

        // ========== 输送控制 ==========
        // 使用 R1 和 R2 全局变量
        if (R1) { // R1 变量是 bool 类型, 直接判断即可
            ConveyorMotor.spin(directionType::fwd, 100, velocityUnits::pct);
            ConveyorMotor2.spin(directionType::rev, 100, velocityUnits::pct);
        }
        else if (R2) {
            ConveyorMotor.spin(directionType::rev, 100, velocityUnits::pct);
            ConveyorMotor2.spin(directionType::fwd, 100, velocityUnits::pct);
        }
        else {
            ConveyorMotor.stop(brakeType::hold);
            ConveyorMotor2.stop(brakeType::hold);
        }
        if (Y) {
            ConveyorMotor2.spin(directionType::fwd, 100, velocityUnits::pct);
            }

        // ========== 发射控制 ==========
        // 使用 L1 和 L2 全局变量
        if (L1) {
            LauncherMotor.spin(directionType::fwd, 100, velocityUnits::pct);
        }
        else if (L2) {
            LauncherMotor.spin(directionType::rev, 100, velocityUnits::pct);
        }
        else {
            LauncherMotor.stop(brakeType::hold);
        }

        // ========== 延时防止 CPU 过载 ==========
        vex::wait(20, vex::msec);
    motorTestControl();

    // 新增
    //testTurnTo();
   // testPIDDistanceForward();
    //testAuton();
}

void userControl() {
    // 新增
    // 用户控制代码
    while (true) {
        if (auto_func_reg == COMPETITION) {
            cout << "User Control" << endl;
            robot_operation_mode = RobotOperationMode::USER_CONTROL;
        }
        allDeviceControl();
        this_thread::sleep_for(2); // 避免占用过多CPU资源
    }
}