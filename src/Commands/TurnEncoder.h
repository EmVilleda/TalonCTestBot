// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef TURNENCODER_H
#define TURNENCODER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Constants.h"

//#define ENCODERFULLREVOLUTION (encoderTicksPerRevo*robotDiameter/wheelDiameter)

/**
 * This Command will drive forward based on a PID Loop in the Talons
 * For now, we'll only drive Talons 3 and 4 since we're having trouble getting Talon 2 to behave.
 *
 * @author ExampleAuthor
 */
class TurnEncoder: public Command {
public:
	TurnEncoder(int _degrees, bool reverseDirection);
	TurnEncoder(int _degrees);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	int targetEncTicks, currentTime;
	bool isFinished;
	int leftStartPos,rightStartPos;
	float encoderFullRevolutions;
};

#endif
