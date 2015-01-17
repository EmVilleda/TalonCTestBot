// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "PneumaticSubsystem.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/ToggleSolenoidCommand.h"

PneumaticSubsystem::PneumaticSubsystem() : Subsystem("PneumaticSubsystem") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	printf("Pneumatic Subsystem Constructor called.\n");
	testSolenoid = RobotMap::pneumaticSubsystemSolenoid;
	solenoidState = testSolenoid->Get();
	printf("PneumaticSubsystem solenoid state is %s\n", solenoidState ? "on" : "off");
}

void PneumaticSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new ToggleSolenoidCommand());
	solenoidState = testSolenoid->Get();
	printf("Pneumatic Subsystem solenoid state toggled to %s\n", solenoidState ? "on" : "off");
}

void PneumaticSubsystem::Toggle() {
	SetSolenoidState(!solenoidState);
}

void PneumaticSubsystem::TurnOn() {
	SetSolenoidState(true);
	solenoidState = testSolenoid->Get();
	printf("Pneumatic Subsystem solenoid state set to %s\n", solenoidState ? "on" : "off");
}

void PneumaticSubsystem::TurnOff() {
	SetSolenoidState(false);
	solenoidState = testSolenoid->Get();
	printf("Pneumatic Subsystem solenoid state toggled to %s\n", solenoidState ? "on" : "off");
}

bool PneumaticSubsystem::GetSolenoidState() {
	return solenoidState;
}

void PneumaticSubsystem::SetSolenoidState(bool state) {
	solenoidState = state;
	testSolenoid->Set(state);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

