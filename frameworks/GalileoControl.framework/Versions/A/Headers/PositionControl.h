//  Created by Chris Harding on 28/08/2012.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The PositionControl object allows you to control Galileo's rotational position for a given axis. You can access the instance through the `positionControlForAxis:` method of the `Galileo` singleton instance.
 
 Control is performed by setting a target position in reference to an origin. Galileo will attempt to rotate to reach the target position as fast and as smoothly as possible. Setting the target position whilst Galileo is already moving will cause Galileo to abandon the current movement and begin moving towards the new target position.
 */

#import <Foundation/Foundation.h>
#import "GalileoCommon.h"
#import "PositionControlDelegate.h"

@interface PositionControl : NSObject

///---------------------------------------------------------------------------------------
/// @name Accessing and setting control properties
///---------------------------------------------------------------------------------------

/** The smallest angle, in degrees, that the accessory can reliably move.
 
 @discussion It is possible to attempt to move in increments smaller than `smallestAngleIncrement`, however the precision of such movements is not guaranteed. Attempts to move in increments less than the `smallestAngleIncrement` will result in actual movements less than or greater than the desired movement. However, the sum of many such small movements will still add up to the expected amount over a long enough sequence.
 */
@property (nonatomic, readonly) double smallestAngleIncrement;

/** Indicates whether the motors should actively hold position whilst stationary.
 
 @discussion When the value of this property is `NO`, the motors will idle when stationary, reducing power consumption and permitting the user to manually rotate the device. This is the default setting.
 
When the value of this property is `YES`, the motors will actively hold a fixed position whilst stationary. This will increase power consumption and will also prevent the user from phyiscally manipulating the unit to rotate to a specific position. However, this setting is useful in certain scenarios when accurately holding a fixed position is required.
 
 @warning When setting this value to `YES`, care must be taken to ensure that it is set to `NO` once no longer required. Failure to do so will lead to increased power consumption and potential user frustration since the device will be locked in a given orientation. Furthermore, use of this setting with a high value for `torque` is strongly discouraged, as this is likely cause heating and damage the motors.
 */
@property (nonatomic) BOOL holdPositionWhenStationary;

/** Motor torque setting as a percentage of maximum possible.
 @discussion A larger torque setting is useful to prevent stalling at greater velocities. Use a smaller torque setting to conserve power during low velocity operation.
 @warning Using a torque setting larger than the default for extended periods may causing heating and damage the motors, especially when `holdPositionWhenStationary` is set to `YES`.
 */
@property (nonatomic) double torque;


///---------------------------------------------------------------------------------------
/// @name Accessing positional information
///---------------------------------------------------------------------------------------

/** The current position, in degress. */
@property (nonatomic, readonly) double currentPosition;

/** The target position, in degress, you wish to set the accessory to. */
@property (nonatomic, readonly) double targetPosition;

/** True if the accessory is idle at the target position. False if the accessory is still moving in an attempt to reach the target postion. */
@property (nonatomic, readonly, getter=isAtTargetPosition) BOOL atTargetPosition;


///---------------------------------------------------------------------------------------
/// @name Resetting the origin
///---------------------------------------------------------------------------------------

/** Resets the origin to the current position.
 
 @discussion After calling this function, all future absolute commands will be in reference to the current position. It is not recommended that you reset the origin whilst the accessory is in motion, therefore you should check the value of `atTargetPosition` before calling this method.
 */
- (void) resetOriginToCurrentPosition;


///---------------------------------------------------------------------------------------
/// @name Controlling absolute position
///---------------------------------------------------------------------------------------

/** Rotate Galileo to a new position.
 
 @param newTargetPosition The target position, in degrees, in relation to the origin.
 @param completionBlock The block to be executed on completion or preemption.
 @param waitUntilStationary If `TRUE` the call blocks untill the accessory has stopped moving.
 @discussion If another method call changes the target position before it has been reached then the previous command will be preempted and the accessory will immediately begin moving towards the new target position. If a completion block is provided then it will be executed either when the target is reached or when the command is preempted.
 
 If `waitUntilStationary` is `TRUE` then the call will block until the target position is reached. If the command is preempted, the call will continue to block until any new target is reached and the accessory is stationary.
 
 @warning You should not call this method from the main thread with `waitUntilStationary` set to `TRUE`. This will lock up the device since some accessory events are processed on the main thread.
 */
- (void) setTargetPosition: (double) newTargetPosition completionBlock:(void (^)(BOOL wasCommandPreempted)) completionBlock waitUntilStationary: (BOOL) waitUntilStationary;


/** Rotate Galileo to a new position.
 
 @param newTargetPosition The target position, in degrees, in relation to the origin.
 @param delegate The delegate to be notified on completion or preemption.
 @param waitUntilStationary If `TRUE` the call blocks untill the accessory has stopped moving.
 @discussion If another method call changes the target position before it has been reached then the previous command will be preempted and the accessory will immediately begin moving towards the new target position. If a delegate is provided then it will be notified either when the target is reached or when the command is preempted.
 
 If `waitUntilStationary` is `TRUE` then the call will block until the target position is reached. If the command is preempted, the call will continue to block until any new target is reached and the accessory is stationary.
 
 @warning You should not call this method from the main thread with `waitUntilStationary` set to `TRUE`. This will lock up the device since some accessory events are processed on the main thread.
 */
- (void) setTargetPosition: (double) newTargetPosition notifyDelegate: (id<PositionControlDelegate>) delegate waitUntilStationary: (BOOL) waitUntilStationary;



///---------------------------------------------------------------------------------------
/// @name Controlling relative position
///---------------------------------------------------------------------------------------

/** Rotate Galileo to a new position, relative to it's current target position. Rotation is clockwise for positive valued increment amounts and anti-clockwise otherwise.
 
 @param amount The amount, in degrees, to increment the target position by.
 @param completionBlock The block to be executed on completion or preemption.
 @param waitUntilStationary If `TRUE` the call blocks untill the accessory has stopped moving.
 @discussion If another method call changes the target position before it has been reached then the previous command will be preempted and the accessory will immediately begin moving towards the new target position. If a completion block is provided then it will be executed either when the target is reached or when the command is preempted.
 
 If `waitUntilStationary` is `TRUE` then the call will block until the target position is reached. If the command is preempted, the call will continue to block until any new target is reached and the accessory is stationary.
 
 @warning You should not call this method from the main thread with `waitUntilStationary` set to `TRUE`. This will lock up the device since some accessory events are processed on the main thread.
 */
- (void) incrementTargetPosition: (double) amount completionBlock:(void (^)(BOOL wasCommandPreempted)) completionBlock waitUntilStationary: (BOOL) waitUntilStationary;

/** Rotate Galileo to a new position, relative to it's current target position. Rotation is clockwise for positive valued increment amounts and anti-clockwise otherwise.
 
 @param amount The amount, in degrees, to increment the target position by.
 @param delegate The delegate to be notified on completion or preemption.
 @param waitUntilStationary If `TRUE` the call blocks untill the accessory has stopped moving.
 @discussion If another method call changes the target position before it has been reached then the previous command will be preempted and the accessory will immediately begin moving towards the new target position. If a delegate is provided then it will be notified either when the target is reached or when the command is preempted.
 
 If `waitUntilStationary` is `TRUE` then the call will block until the target position is reached. If the command is preempted, the call will continue to block until any new target is reached and the accessory is stationary.
 
  @warning You should not call this method from the main thread with `waitUntilStationary` set to `TRUE`. This will lock up the device since some accessory events are processed on the main thread.
 */
- (void) incrementTargetPosition: (double) amount notifyDelegate: (id<PositionControlDelegate>) delegate waitUntilStationary: (BOOL) waitUntilStationary;








@end
