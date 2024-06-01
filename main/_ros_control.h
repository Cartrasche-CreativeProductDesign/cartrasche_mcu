#ifndef _ROS_CONTROL_H
#define _ROS_CONTROL_H
#include "config.h"
#include "_motor_control.h"
#include "_led_control.h"

// ROS usage
ros::NodeHandle n;
std_msgs::String str_msg;
ros::Publisher rosduino("rosduino", &str_msg);
char cmdvelcallback[18] = "rcvd cmdvel";
char stcallback[18] = "rcvd st";

void stopCallback(const std_msgs::Int32& stop_vel){
  if(stop_vel.data == 1){
    n.loginfo("stop");
    turn_off_motor();
    delay(10);
  }
}

// Subscriber Callbacks
void cmdvelCallback(const geometry_msgs::Twist& cmd_vel){
  str_msg.data = cmdvelcallback;
  rosduino.publish(&str_msg);

  float linx = cmd_vel.linear.x;
  float angz = cmd_vel.angular.z;
 
  // int spd = calculateSpeed(abs(linx));
  ////////////// MODIFIED //////////////
  int spd = 123;
  //////////////////////////////////////
  int ang = 123;
  int stopvel = 123;
  

  if(linx > 0.0){
    n.loginfo("linear fwd");
    ////////////// MODIFIED //////////////
    if(linx<0.1){
      spd = calculateSpeed(0.03);
    }
    else{
      spd = calculateSpeed(abs(linx));
    }
    //////////////////////////////////////
    fb_control(0, spd);
    delay(10);
    if(abs(angz) > 0.1){
      ang = calculateAngle(angz);
      n.loginfo("angular_1");
      lr_control(ang);
      delay(10);
    }
    else{
      //indicFWD(); //////////////////////////////////////
    }
  }
  else if(linx < 0.0){
    n.loginfo("linear bwd");
    if(abs(linx)<0.1){
      spd = calculateSpeed(0.03);
    }
    else{
      spd = calculateSpeed(abs(linx));
    }
    fb_control(1, spd);
    delay(10);
    if(abs(angz) > 0.1){
      ang = calculateAngle(angz);
      n.loginfo("angular_2");
      lr_control(ang);
      delay(10);
    }
    else{
      //indicBWD(); //////////////////////////////////////////
    }
  }
  else{
    n.loginfo("linear zero");
    if(abs(angz) > 0.0){
      ang = calculateAngle(angz);
      n.loginfo("angular_3");
      lr_control(ang);
      delay(10);
    }
    else{
      n.loginfo("stop");
      turn_off_motor();
      delay(10);
    }
  }

}

void stCallback(const std_msgs::Int32& switch_tray){
  str_msg.data = stcallback;
  rosduino.publish(&str_msg);

  if(switch_tray.data == 1){
    mid2top();
  }
  
  if(switch_tray.data == 2){
    bot2top();
  }
}

#endif
