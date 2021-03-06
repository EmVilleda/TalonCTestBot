// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

CANTalon* RobotMap::driveFrontLeft = NULL;
CANTalon* RobotMap::driveFrontRight = NULL;
CANTalon* RobotMap::driveBackLeft = NULL;
CANTalon* RobotMap::driveBackRight = NULL;

RobotDrive* RobotMap::robotDrive = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
DoubleSolenoid* RobotMap::pneumaticSubsystemSolenoid = NULL;
//Compressor* RobotMap::workingCompressor = NULL;
CANTalons* RobotMap::Ct = NULL;
//AnalogInput* RobotMap::distanceSensor = NULL;
DigitalInput* RobotMap::colorSensor = NULL;

//CANTalon* RobotMap::pickupMotorMain = NULL;
//CANTalon* RobotMap::pickupMotorFollow = NULL;
//Encoder* RobotMap::pickupEncoder = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// Front Talons:  2=right  4=left
	// Back  Talons:  3=right  5=left
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//LiveWindow* lw = LiveWindow::GetInstance();
	Ct = new CANTalons();


	driveFrontLeft = Ct->Init(4, (char *)"FrontLeft");
	//lw->AddActuator("DriveSubsystem", "motorControllerFrontLeft", (CANTalon*) driveFrontLeft);
	driveFrontRight =  Ct->Init(2, (char *)"FrontRight");
	//lw->AddActuator("DriveSubsystem", "motorControlleFrontRight", (CANTalon*) driveSubsystemmotorControlleFrontRight);
	driveBackLeft  =  Ct->Init(5, (char *)"BackLeft");
	//lw->AddActuator("DriveSubsystem", "motorControllerBackLeft", (CANTalon*) driveSubsystemmotorControllerBackLeft);
	driveBackRight =  Ct->Init(3, (char *)"BackRight");
	//lw->AddActuator("DriveSubsystem", "motorControllerBackRight", (CANTalon*) driveSubsystemmotorControllerBackRight);

	robotDrive = new RobotDrive(driveFrontLeft,	driveFrontRight);
	printf("Robot Drive initialized\n");
	
	robotDrive->SetSafetyEnabled(false);
    robotDrive->SetExpiration(0.1);
    robotDrive->SetSensitivity(0.5);
    robotDrive->SetMaxOutput(1);
    driveFrontLeft->SetVoltageRampRate(0.1);
    driveFrontRight->SetVoltageRampRate(0.1);
    driveBackLeft->SetVoltageRampRate(0.05);
    driveBackRight->SetVoltageRampRate(0.05);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    // Invert the motors here to to get the appropriate behavior from the two stage gearbox
    robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
    //robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
    robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
    //robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);

    // Set the front talons to voltage mode
    driveFrontLeft->SetControlMode(CANSpeedController::kPercentVbus);
    driveFrontRight->SetControlMode(CANSpeedController::kPercentVbus);
    driveBackLeft->SetControlMode(CANSpeedController::kPercentVbus);
    driveBackRight->SetControlMode(CANSpeedController::kPercentVbus);
    // Set the back talons to follow the front talons
    driveBackLeft->SetControlMode(CANSpeedController::kFollower);
    driveBackLeft->Set(4);
    driveBackLeft->EnableControl();
    driveBackRight->SetControlMode(CANSpeedController::kFollower);
    driveBackRight->Set(2);
    driveBackRight->EnableControl();

    printf("Back Left %d\n", driveBackLeft->GetControlMode());
    printf("Back Right %d\n", driveBackRight->GetControlMode());


    printf("Motor controller parameters set\n");

    pneumaticSubsystemSolenoid = new DoubleSolenoid(5, 0, 1);
    //workingCompressor = new Compressor(11);
    //workingCompressor->SetClosedLoopControl(true);
    //workingCompressor->Start();
    //printf("Compressor closed loop set to true, compressor is %s, compressor switch is %s, current=%f.\n", (workingCompressor->Enabled() ? "enabled" : "disabled"),
    //		(workingCompressor->GetPressureSwitchValue() ? "on" : "off"), workingCompressor->GetCompressorCurrent());


    colorSensor = new DigitalInput(0);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
