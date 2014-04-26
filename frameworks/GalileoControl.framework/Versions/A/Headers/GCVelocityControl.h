//  Created by Chris Harding on 28/08/2012.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The GCVelocityControl object allows you to control Galileo's angular velocity for a given axis. You can access the instance through the `velocityControlForAxis:` method of the `Galileo` singleton instance.
 
 Control is performed by setting a target velocity. Galileo will attempt to accelerate to reach the target velocity as fast and as smoothly as possible. Setting the target velocity whilst Galileo is already moving will cause Galileo to immediately begin accelerating towards the new target velocity. Once the target velocity is reached, Galileo will continue moving at a constant velocity until a new target velocity is supplied.
 */

#import <Foundation/Foundation.h>
#import "GCCommon.h"
#import "GCVelocityControlDelegate.h"

@interface GCVelocityControl : NSObject


///---------------------------------------------------------------------------------------
/// @name Detecting when target velocity is reached
///---------------------------------------------------------------------------------------

/** Block-based handler for when target velocity is reached. */
@property (nonatomic, copy) void (^controlDidReachTargetVelocity) (void);

/** Delegate-based handler for when target velocity is reached.
 @discussion  The delegate must adopt the GCVelocityControlDelegate protocol. Delegate is not retained.
 */
@property (nonatomic, assign) id<GCVelocityControlDelegate> delegate;

/** True if the accessory is cruising at the target velocity. False if the accessory is still accelerating towards the target velocity. */
@property (nonatomic, readonly, getter=isAtTargetVelocity) BOOL atTargetVelocity;



///---------------------------------------------------------------------------------------
/// @name Controlling the target velocity
///---------------------------------------------------------------------------------------

/** The target velocity, in degrees per second.
 @discussion  Upon setting the target velocity, Galileo will attempt to accelerate to reach the target velocity as fast and as smoothly as possible. Setting the target velocity whilst Galileo is already moving will cause Galileo to immediately begin accelerating towards the new target velocity. Once the target velocity is reached, Galileo will continue moving at a constant velocity until a new target velocity is supplied.
 */
@property (nonatomic) double targetVelocity;


///---------------------------------------------------------------------------------------
/// @name Accessing control parameters
///---------------------------------------------------------------------------------------

/** The current velocity Galileo is moving at, in degrees per second.
 */
@property (nonatomic, readonly) double velocity;

/** The maximum velocity Galileo is able to move at, in degrees per second.
 */
@property (nonatomic, readonly) double maxVelocity;

/** The minimum velocity Galileo is able to move at, in degrees per second.
 */
@property (nonatomic, readonly) double minVelocity;

/** Motor torque setting as a percentage of maximum possible.
 @discussion A larger torque setting is useful to prevent stalling at greater velocities. Use a smaller torque setting to conserve power during low velocity operation.
 @warning Using a torque setting larger than the default for extended periods may causing heating and damage the motors.
 */
@property (nonatomic) double torque;


@end
