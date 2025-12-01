#include "vex.h"
#include "my-timer.h"
#include "basic_function.h"
#include "controller.h" // 确保包含了 controller.h
#include <iostream>
#include <cmath>
#include "robot_config.h"
using namespace std;
using namespace vex;

// ========== 自动阶段测试函数 ==========
void autonTest() {
    Drive.driveFor(directionType::fwd, 88, distanceUnits::cm);
    wait(150, msec);  // 短暂稳定
    ConveyorMotor.spinFor(directionType::fwd, 1, rotationUnits::rev, 50, velocityUnits::pct);
    Drive.turnFor(turnType::right, 40, rotationUnits::deg);
    Drive.driveFor(directionType::fwd, 62, distanceUnits::cm);
    LauncherMotor.spinFor(directionType::fwd, 2, rotationUnits::rev, 80, velocityUnits::pct);
// 1.2 【预留】释放预装棱块到长得分桥
    // TODO: 添加你的释放机构代码
    // 示例：
    // LauncherMotor.spinFor(directionType::fwd, 1, rotationUnits::rev, 80, velocityUnits::pct);
    wait(300, msec);  // 等待棱块完全释放
    
    // ========== 阶段2：第一轮场地棱块采集 ==========
    // 目标：采集场地初始布局的3-4个棱块
    
    // 2.1 微调角度，面向场地棱块密集区
    // 小角度转向，避免大幅度旋转导致定位偏差
    Drive.turnFor(turnType::right, 135, rotationUnits::deg);
    wait(150, msec);
    
    // 2.2 前进到棱块区域（约30-40cm）
    Drive.driveFor(directionType::fwd, 70, distanceUnits::cm);
    wait(150, msec);
    
    // 2.3 【预留】启动采集机构，吸取/抓取棱块
    ConveyorMotor.spinFor(directionType::fwd, 4, rotationUnits::rev, 50, velocityUnits::pct);
// TODO: 添加你的采集代码
    // 示例：
    // ConveyorMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    wait(1000, msec);  // 采集3-4个棱块（时间根据机构效率调整）
    // ConveyorMotor.stop(brakeType::hold);
    
    // 2.4 直线后退回到得分桥位置
    Drive.driveFor(directionType::rev, 35, distanceUnits::cm);
    wait(150, msec);
    
    // 2.5 回正方向，面向得分桥
    Drive.turnFor(turnType::right, 30, rotationUnits::deg);
    wait(150, msec);
    
    // 2.6 【预留】释放第一批棱块到长得分桥
    // TODO: 添加你的释放代码
        LauncherMotor.spinFor(directionType::fwd, 4, rotationUnits::rev, 80, velocityUnits::pct);
// ConveyorMotor.spinFor(directionType::fwd, 2, rotationUnits::rev, 80, velocityUnits::pct);
    // LauncherMotor.spinFor(directionType::fwd, 1.5, rotationUnits::rev, 100, velocityUnits::pct);
    wait(800, msec);  // 等待所有棱块完全得分
    
    // ========== 阶段3：第二轮场地棱块采集（补充） ==========
    // 目标：确保总共至少7个棱块得分
    
    // 3.1 再次前进到棱块区域采集剩余棱块
    Drive.turnFor(turnType::left, 30, rotationUnits::deg);
    wait(150, msec);
    
    Drive.driveFor(directionType::fwd, 40, distanceUnits::cm);
    wait(150, msec);
    
    // 3.2 【预留】第二轮采集
    ConveyorMotor.spinFor(directionType::fwd, 3, rotationUnits::rev, 50, velocityUnits::pct);
// TODO: 添加采集代码
    // ConveyorMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    wait(1000, msec);  // 再采集2-3个棱块
    // ConveyorMotor.stop(brakeType::hold);
    
    // 3.3 后退回到得分桥
    Drive.driveFor(directionType::rev, 40, distanceUnits::cm);
    wait(150, msec);
    
    Drive.turnFor(turnType::right, 30, rotationUnits::deg);
    wait(150, msec);
    
    // 3.4 【预留】释放第二批棱块
    LauncherMotor.spinFor(directionType::fwd, 3, rotationUnits::rev, 80, velocityUnits::pct);
// TODO: 添加释放代码
    // ConveyorMotor.spinFor(directionType::fwd, 2, rotationUnits::rev, 80, velocityUnits::pct);
    // LauncherMotor.spinFor(directionType::fwd, 1.5, rotationUnits::rev, 100, velocityUnits::pct);
    wait(800, msec);
    
    // ========== 阶段4：离开停泊区（必须！） ==========
    // 目标：确保机器人完全脱离停泊区白色胶带边界
    
    // 4.1 直线后退到安全距离
    // 停泊区深度428mm，后退至少50cm确保完全脱离
    Drive.driveFor(directionType::rev, 50, distanceUnits::cm);
    wait(200, msec);
    
    // 4.2 【可选】微调确保稳定停在场地中央
    Drive.driveFor(directionType::fwd, 5, distanceUnits::cm);
    wait(100, msec);
    Brain.Screen.printAt(1, 40, "Conservative Auto Done!");
}

// ========== 自动阶段主函数 ==========
void autonomous(void) {
    cout << "Entering autonomous" << endl;
    robot_operation_mode = RobotOperationMode::AUTO;
    MyTimer auto_timer;

     // ========== 阶段1：倒车对准得分桥，释放预装（2秒） ==========
    // 机器人初始位置：停泊区，屁股朝外
    // 倒车让后方释放口对准最近的得分桥
     Drive.turnFor(turnType::left, 95, rotationUnits::deg);
    wait(100, msec);
    Drive.driveFor(directionType::fwd, 52, distanceUnits::cm);
    wait(100, msec);
    Drive.turnFor(turnType::right, 90, rotationUnits::deg);
    wait(100, msec);
    Drive.driveFor(directionType::fwd, 27, distanceUnits::cm);
    wait(100, msec);
    // 启动输送，预装从后方掉进得分桥
    ConveyorMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    wait(2000, msec); 
    ConveyorMotor2.spin(directionType::rev, 100, velocityUnits::pct);
    wait(2000, msec); // 1.2秒确保预装完全掉落
    ConveyorMotor.stop(brakeType::hold);
    LauncherMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    wait(2500, msec);
    Drive.driveFor(directionType::rev, 20, distanceUnits::cm);
    wait(100, msec);
    Drive.turnFor(turnType::right, 95, rotationUnits::deg);
    wait(100, msec);
    Drive.driveFor(directionType::fwd, 45, distanceUnits::cm);
    wait(100, msec);
    
    // ========== 阶段2：zhuanxciang ==========
    Drive.turnFor(turnType::right, 90, rotationUnits::deg);
    wait(100, msec);
    Drive.driveFor(directionType::fwd, 25, distanceUnits::cm);
    wait(100, msec);
    ConveyorMotor.spin(directionType::fwd, 80, velocityUnits::pct);
    // 小幅度前进，增加采集面积
    Drive.driveFor(directionType::fwd, 30, distanceUnits::cm);
    wait(1500, msec);  // 继续采集1.5秒
    ConveyorMotor.stop(brakeType::hold);
    // ========== 阶段3：? ==========
    Drive.turnFor(turnType::right, 45, rotationUnits::deg);
    wait(100, msec);
      Drive.driveFor(directionType::rev, 5, distanceUnits::cm);
    wait(100, msec);
    LauncherMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    wait(2500, msec);  // 持续2.5秒确保全部发射
    LauncherMotor.stop(brakeType::coast);
    // ========== 阶段7：离开停泊区（1秒） ==========
    // qianjin一点确保完全脱离停泊区（必须！）
    Drive.driveFor(directionType::fwd, 20, distanceUnits::cm);
    
    Brain.Screen.printAt(1, 40, "AUTO DONE!");
    cout << "Emergency Auto Complete!" << endl;
    
    // 保持运行
    while (true) {
        vex::wait(20, vex::msec);
    }
}

// ========== 手动控制主函数 (修改后) ==========
void usercontrol(void) {
    robot_operation_mode = RobotOperationMode::USER_CONTROL;
    
    while (true) {
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
        }
        else if (R2) {
            ConveyorMotor.spin(directionType::rev, 100, velocityUnits::pct);
        }
        else {
            ConveyorMotor.stop(brakeType::hold);
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
    }
}

