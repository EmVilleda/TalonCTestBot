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
	static float joystickValueCap = .5;

	// This is the voltage from the distanceSensor. As we get closer to an obstacle, the voltage increases
	// until we get really close. This should be calibrated so we can read the actual distance, but for
	// now we'll just guess at a voltage threshold.
	static float distanceSensorThreshold = 0.7;

#endif /* SRC_CONSTANTS_H_ */
