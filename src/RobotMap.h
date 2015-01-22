// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "Subsystems/CANTalons.h"

/*
 * PDP Channel Map
 * Channel 15 -> Talon 1
 * Channel 14 -> Talon 2
 * Channel 13 -> Talon 3
 * Channel 12 -> Talon 4
 */

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
<<<<<<< HEAD
	static CANTalon* driveSubsystemMotorControllerFrontLeft;
	static CANTalon* driveSubsystemMotorControlleFrontRight;
	static CANTalon* driveSubsystemMotorControllerBackLeft;
	static CANTalon* driveSubsystemMotorControllerBackRight;
	static RobotDrive* robotDrive;
	static CANTalons* Ct;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static DoubleSolenoid* pneumaticSubsystemSolenoid;
	static Compressor* workingCompressor;
=======
	static SpeedController* driveSubsystemLFront;
	static SpeedController* driveSubsystemLBack;
	static SpeedController* driveSubsystemRFront;
	static SpeedController* driveSubsystemRBack;
	static RobotDrive* driveSubsystemRobotDrive41;
	static Encoder* driveSubsystemLEncoder;
	static Encoder* driveSubsystemREncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
>>>>>>> origin/encoder

	static void init();
};
#endif
