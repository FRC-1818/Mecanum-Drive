#include <IterativeRobot.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <RobotDrive.h>
#include <Timer.h>
#include "WPILib.h"
#include <XboxController.h>

class Robot: public frc::IterativeRobot {
public:
	Robot() {
		myRobot.SetExpiration(0.1);
		timer.Start();
		myRobot.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		myRobot.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		// You may need to change or remove this to match your robot
	}

private:
	frc::RobotDrive myRobot {1, 2, 3, 4};  // Robot drive system
	frc::XboxController leftstick { 0 };       // Xbox joystick
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	frc::Timer timer;

	void AutonomousInit() override {
		timer.Reset();
		timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 2 seconds
		/*if (timer.Get() < 2.5) {
		 myRobot.MecanumDrive_Cartesian(0.0, -0.5, 0.0);  // Drive forwards with half speed
		 } else {
		 if ((timer.Get() > 2.5) && (timer.Get() < 2.93)) {
		 myRobot.MecanumDrive_Cartesian(0.0, 0.0, 1.0 ); // Turn left with full speed
		 }
		 else {
		 if (timer.Get() > 2.93){
		 myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0);  // Stop robot
	    }
	  }
	}*/  // Middle

		/*if (timer.Get() < 2.5) {
			myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0); // Drive forwards with half speed
		} else {
			if ((timer.Get() > 2.5) && (timer.Get() < 3.0)) {
				myRobot.MecanumDrive_Cartesian(0.0, 0.0, 0.5); // Turn left with full speed
			} else {
				if ((timer.Get() > 3.0) && (timer.Get() < 4.25)) {
					myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0); // Stop robot
				} else {
			      if (timer.Get() > 4.25 ) {
				     myRobot.MecanumDrive_Cartesian(0.0, 0.0, 0.0);
			        }
			    }
		    }
	    }*/ //left

		if (timer.Get() < 2.5) {
					myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0); // Drive forwards with half speed
				} else {
					if ((timer.Get() > 2.5) && (timer.Get() < 3.0)) {
						myRobot.MecanumDrive_Cartesian(0.0, 0.0, -0.5); // Turn left with full speed
					} else {
						if ((timer.Get() > 3.0) && (timer.Get() < 4.25)) {
							myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0); // Stop robot
						} else {
					      if (timer.Get() > 4.25 ) {
						     myRobot.MecanumDrive_Cartesian(0.0, 0.0, 0.0);
					        }
					    }
				    }
		         }                                                           //Right
    }
void TeleopInit() override {

}

void TeleopPeriodic() override {
	// Drive with arcade style (use right stick)
	myRobot.MecanumDrive_Cartesian(leftstick.GetRawAxis(1), // 0,1 is the X and Y axis of the leftstick
	leftstick.GetRawAxis(0), leftstick.GetRawAxis(4));
	/*if (leftstick.GetRawButton(8)) {
		if (timer.Get() < 2.5) {
			myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0); // Drive forwards with half speed
		} else {
			if ((timer.Get() > 2.5) && (timer.Get() < 3.0)) {
				myRobot.MecanumDrive_Cartesian(0.0, 0.0, 0.5); // Turn left with full speed
			} else {
				if ((timer.Get() > 3.0) && (timer.Get() < 4.25)) {
					myRobot.MecanumDrive_Cartesian(0.5, 0.0, 0.0); // Stop robot
				}
			  }
	        }
          }*/
      }

void TestPeriodic() override {
lw->Run();
}
};

START_ROBOT_CLASS(Robot)
