#include <iostream>
#include  <iomanip>
#include <thread>
#include <chrono>
#include "MotorBridgeCape.h"
#include "Channel.h"

int main (int argc, char *argv[])
{
  using namespace std::chrono_literals;
  // std::chrono::seconds sec(1);
  
  MotorBridgeCape cape("/dev/i2c-2");
  cape.setDCMotorFrequency(1000);

  cape.setChannel1(ChannelType::DcDc);
  cape.setChannel2(ChannelType::DcDc);


  auto channelDcDc1 = static_cast<ChannelDcDc*>(cape.getChannel1());
  auto channelDcDc2 = static_cast<ChannelDcDc*>(cape.getChannel2());

  auto motor1A = dynamic_cast<DCMotor*>(channelDcDc1->getMotorA());
  auto motor1B = dynamic_cast<DCMotor*>(channelDcDc1->getMotorB());
  auto motor2A = dynamic_cast<DCMotor*>(channelDcDc2->getMotorA());
  auto motor2B = dynamic_cast<DCMotor*>(channelDcDc2->getMotorB());
  if (!motor1A || !motor1B || !motor2A || !motor2B)
    {
      return EXIT_FAILURE;
    }
  
  std::cout << "power to 0.5" << std::endl;
    
  motor1A->power(0.5);
  motor1B->power(-0.5);
  motor2A->power(0.5);
  motor2B->power(-0.5);

  std::this_thread::sleep_for(10s);

  std::cout << "stop" << std::endl;

  motor1A->stop();
  motor1B->stop();
  motor2A->stop();
  motor2B->stop();


  /*
reg = 01, data = [04, e8, 03, 00, 00]
reg = 01, data = [09, 00]
reg = 01, data = [0a, 03]
reg = 01, data = [15, 00]
reg = 01, data = [16, 03]
reg = 01, data = [04, e8, 03, 00, 00]
reg = 01, data = [09, 00]
reg = 01, data = [0a, 03]
reg = 01, data = [15, 00]
reg = 01, data = [16, 03]
reg = 01, data = [04, e8, 03, 00, 00]
reg = 01, data = [21, 00]
reg = 01, data = [22, 03]
reg = 01, data = [2d, 00]
reg = 01, data = [2e, 03]
reg = 01, data = [04, e8, 03, 00, 00]
reg = 01, data = [21, 00]
reg = 01, data = [22, 03]
reg = 01, data = [2d, 00]
reg = 01, data = [2e, 03]
power to 0.5
reg = 01, data = [16, 01]
reg = 01, data = [17, f4, 01, 00, 00]
reg = 01, data = [0a, 01]
reg = 01, data = [0b, f4, 01, 00, 00]
reg = 01, data = [2e, 01]
reg = 01, data = [2f, f4, 01, 00, 00]
Error accessing 0x4B: Check your I2C address
reg = 01, data = [22, 01]
reg = 01, data = [23, f4, 01, 00, 00]
stop
reg = 01, data = [16, 03]
reg = 01, data = [0a, 03]
reg = 01, data = [2e, 03]
reg = 01, data = [22, 03]

  */
  
  return 0;
}
