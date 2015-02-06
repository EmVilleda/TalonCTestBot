/*
 * Constants.h
 *
 *  Created on: Jan 27, 2015
 *      Author: Ligerbots
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

	// These are constants that will be used for testing and tuning

	// The following will limit the max drive speed
	// For competition, this should be 1.0
	// Until then, we'll keep it slow.
	static float joystickValueCap = 0.5;

	// This is the voltage from the distanceSensor. As we get closer to an obstacle, the voltage increases
	// until we get really close. This should be calibrated so we can read the actual distance, but for
	// now we'll just guess at a voltage threshold.
	static float distanceSensorThreshold = 0.7;
	// This is the distance we want to go forward in autonomous to get the tote and the robot into the
	static float autoSetDistanceForward = 0.0;

	// The number of encoder ticks which correspond to 1 revolution of a wheel
	static float encoderTicksPerRevo = 1024;

	// The diameter of the robot
	static float robotDiameter = 25.3125;

	// The diameter of the wheel
	static float wheelDiameter = 6.25;

#endif /* SRC_CONSTANTS_H_ */
