// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Drive.h"
#include "../Constants.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSubsystem);
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	float y = Robot::oi->joystick->GetY();
	// Note that the sense of Y is negative, That is, if one pushes the joystick forward, Y is negative.
	// So a negative y value means we want to drive forward.
	// The ArcadeDrive method seems to expect this.
	float x = Robot::oi->joystick->GetRawAxis(4);
	if(fabs(y)>joystickValueCap){
		y=joystickValueCap * (y/fabs(y)); // y/fabs(y) is either 1 or -1 depending on the sign of y.
	}
	if(fabs(x)>joystickValueCap){
		x=joystickValueCap * (x/fabs(x)); // x/fabs(x) is either 1 or -1 depending on the sign of x.
	}


	bool isDistSensorOK = RobotMap::distanceSensor->GetVoltage() <= distanceSensorThreshold;
	// If the distanceSensor voltage is > 0.6, we are close enough to the target.
	// Only allow us to drive backward which means positive y
	if (isDistSensorOK || (!isDistSensorOK && y>0)) {
//		On an XBox controller, RawAxis4 is the X axis of the right stick
//		We will use this for the left/right control only
//		Drive(a,b) where a is the magnitude and b is the curve of it
		Robot::driveSubsystem->robotDrive->ArcadeDrive(y,x);
	}
	else{
		Robot::driveSubsystem->robotDrive->ArcadeDrive(0,0,true);
	}
	SmartDashboard::PutNumber("Drive Command Y", y);
	SmartDashboard::PutNumber("Drive Command X", x);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
	End();

}
