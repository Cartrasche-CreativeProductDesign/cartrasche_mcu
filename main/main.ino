
#include "config.h"
#include "_step_control.h"
#include "_led_control.h"
#include "_motor_control.h"
#include "_ros_control.h"

// SUbscriber Declaration
ros::Subscriber<geometry_msgs::Twist> subCmdVel("cmd_vel", &cmdvelCallback );
ros::Subscriber<std_msgs::Int32> subStopVel("stop_vel", &stopCallback );
ros::Subscriber<std_msgs::Int32> subSwitch("switch_tray", &stCallback );
// Publisher Declaration
char hb[18] = "arduino heartbeat";
ros::Publisher heartbeat("heartbeat", &str_msg);
std_msgs::Int16 int_msg;
ros::Publisher current_fb_speed_pub("current_fb_speed", &int_msg);
ros::Publisher current_lr_speed_pub("current_lr_speed", &int_msg);

void setupMotors()
{
  // BLDC
  initialize_bldc();
  // STEPPER
  initialize_steppers();
}

void setupPheris()
{
  pinMode(MID2TOP, INPUT);
  pinMode(BOT2TOP, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  initializeLED();
  //initializeSTRIPS();
}

void setupRegister(){
  int myEraser = 7; // this is 111 in binary and is used as an eraser
  TCCR4B &= ~myEraser; // this operation (AND plus NOT), set the three bits in TCCR2B to 0
  int myPrescaler = 1; // this could be a number in [1 , 6]. In this case, 3 corresponds in binary to 011.
  TCCR4B |= myPrescaler; //this operation (OR), replaces the last three bits in TCCR2B with our new value 011
}

void setup()
{ 
  setupRegister();
  setupMotors();  
  setupPheris();
  // ROSSERIAL with Jetson
  n.initNode();
  n.advertise(heartbeat);
  n.advertise(rosduino);
  n.subscribe(subCmdVel);
  n.subscribe(subSwitch);
  n.subscribe(subStopVel);
  n.advertise(current_fb_speed_pub);
  n.advertise(current_lr_speed_pub);
//  spinDown();
//  rotateTopManual();
//  rotateBotManual();
//  spinDownLit();
}

void loop()
{ 
  str_msg.data = hb;
  heartbeat.publish(&str_msg);

  int_msg.data = current_fb_speed;
  current_fb_speed_pub.publish(&int_msg);
  int_msg.data = current_lr_speed;
  current_lr_speed_pub.publish(&int_msg);
  
  n.spinOnce();
  delay(200);

  int M2T_bs = digitalRead(MID2TOP);
  int B2T_bs = digitalRead(BOT2TOP);

  if(M2T_bs == HIGH){
    show_blue(100);
    mid2top();
    delay(1000);
  }
  if(B2T_bs == HIGH){
    show_yellow(100);
    bot2top();
    delay(1000);
  }
}
