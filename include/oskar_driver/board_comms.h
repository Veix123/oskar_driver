#ifndef BOARDCOMMS_H
#define BOARDCOMMS_H
#include <oskar_driver/oskar_packet.h>
#include <ros/ros.h>
#include <serial/serial.h>
#include <string.h>

namespace ahhaa_oskar
{
class BoardComms
{
public:
  BoardComms(std::string portName, int baudrate);
  ~BoardComms();
  void send(OskarPacket packet);

private:
  void tryConnect();
  void reconnect(const ros::TimerEvent& event);
  serial::Serial serial_;
  ros::NodeHandle nh_;
  ros::Timer timer_;
};

}  // namespace ahhaa_oskar

#endif