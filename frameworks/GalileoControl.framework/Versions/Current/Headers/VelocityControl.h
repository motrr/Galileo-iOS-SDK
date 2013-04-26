//  Created by Chris Harding on 28/08/2012.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The VelocityControl object allows you to control Galileo's angular velocity for a given axis. You can access the instance through the `velocityControlForAxis:` method of the `Galileo` singleton instance.
 
 Control is performed by setting a target velocity. Galileo will attempt to accelerate to reach the target velocity as fast and as smoothly as possible. Setting the target velocity whilst Galileo is already moving will cause Galileo to immediately begin accelerating towards the new target velocity. Once the target velocity is reached, Galileo will continue moving at a constant velocity until a new target velocity is supplied.
 */

#import <Foundation/Foundation.h>
#import "GalileoCommon.h"
#import "VelocityControlDelegate.h"

@interface VelocityControl : NSObject 


///---------------------------------------------------------------------------------------
/// @name Setting and Getting the Delegate
///---------------------------------------------------------------------------------------

/** The delegate of the VelocityControl object.
 @discussion  The delegate must adopt the VelocityControlDelegate protocol. The delegate is not retained.
 */
@property (nonatomic, assign) id<VelocityControlDelegate> delegate;


///---------------------------------------------------------------------------------------
/// @name Controlling the target velocity
///---------------------------------------------------------------------------------------

/** The target velocity, in degrees per second.
 @discussion  Upon setting the target velocity, Galileo will attempt to accelerate to reach the target velocity as fast and as smoothly as possible. Setting the target velocity whilst Galileo is already moving will cause Galileo to immediately begin accelerating towards the new target velocity. Once the target velocity is reached, Galileo will continue moving at a constant velocity until a new target velocity is supplied. 
 */
@property (nonatomic) double targetVelocity;

/** True if the accessory is cruising at the target velocity. False if the accessory is still accelerating towards the target velocity. */
@property (nonatomic, readonly, getter=isAtTargetVelocity) BOOL atTargetVelocity;


///---------------------------------------------------------------------------------------
/// @name Accessing control parameters
///---------------------------------------------------------------------------------------

/** The current position, in degress. */
//@property (nonatomic, readonly) double currentPosition;

/** The current velocity Galileo is moving at.
 */
@property (nonatomic, readonly) double currentVelocity;

/** The maximum velocity Galileo is able to move at.
 */
@property (nonatomic, readonly) double maxVelocity;



@end
