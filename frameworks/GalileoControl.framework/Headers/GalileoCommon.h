//  Created by Chris Harding on 11/07/2012.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//
/** This header defines enumerations and constants common throughout the framework and required in code that makes use of it. Documentation is available in the "Useful Definitions" file, since appledoc does not support constants at the time of writing.
 */

#define SIMULATE_ACCESSORY 0

enum {
	GalileoControlAxisPan = 0x0,
	GalileoControlAxisTilt = 0x01
};
typedef NSUInteger GalileoControlAxis;

enum {
    GalileoModePositionControl,
	GalileoModeVelocityControl,
    GalileoModeStationary
};
typedef NSUInteger GalileoMode;

enum {
	GalileoQueueEndBehaviourFloat = 0x0,
    GalileoQueueEndBehaviourHold = 0x1,
    GalileoQueueEndBehaviourMaintain = 0x2
};
typedef NSUInteger GalileoQueueEndBehaviour;

extern NSString *const GalileoDidConnectNotification;
extern NSString *const GalileoDidDisconnectNotification;




