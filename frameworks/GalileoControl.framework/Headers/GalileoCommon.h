//  Created by Chris Harding on 11/07/2012.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//
/** This header defines enumerations and constants common throughout the framework and required in code that makes use of it.
 */

#define SIMULATE_ACCESSORY 0

/*!
 @enum			GalileoControlAxis
 @abstract		These constants can be passed to control methods to indicate which axis is to be controlled.
 
 @constant		GalileoControlAxisPan
 Control the pan axis.
 @constant		GalileoControlAxisTilt
 Control the tilt axis.
 */
enum {
	GalileoControlAxisPan = 0x0,
	GalileoControlAxisTilt = 0x01
};
typedef NSUInteger GalileoControlAxis;

// TODO - explain the following more

/*!
 @enum			GalileoMode
 @abstract		These constants can be used to access and select the curent mode of the Galileo API.
 
 @constant		GalileoModeIdle
 Default mode when disconnected or when no mode has been selected.
 @constant		GalileoModePositionControl
 Mode for using PositionControl.
 @constant		GalileoModeVelocityControl
 Mode for using VelocityControl.
 @constant		GalileoModeFirmwareManagement
 Mode for using PositionControl.
 */
enum {
    GalileoModePositionControl,
	GalileoModeVelocityControl,
    GalileoModeStationary
};
typedef NSUInteger GalileoMode;


/*!
 @enum			GalileoQueueEndBehaviour
 @abstract      These constants can be passed to acceleration methods to determine how the Galileo should behave when the acceleration command queue is empty.
 
 @constant		GalileoQueueEndBehaviourFloat
 Idle the motors.
 @constant		GalileoQueueEndBehaviourHold
 Actively hold position (this will consume power while stationary).
 @constant		GalileoQueueEndBehaviourMaintain
 Continue moving at the previous velocity.
 */
enum {
	GalileoQueueEndBehaviourFloat = 0x0,
    GalileoQueueEndBehaviourHold = 0x1,
    GalileoQueueEndBehaviourMaintain = 0x2
};
typedef NSUInteger GalileoQueueEndBehaviour;