//  Created by Chris Harding on 11/14/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** This protocol defines an interface for delegates of a `PositionControl` object to be notified when a movement control command has either completed or been overridden by another command.
 
 A `PositionControlDelegate` instance is specified for each call to Galileo methods that update the target position, such as `setTargetPosition:notifyDelegate:waitUntilStationary:`.
 */

#import <Foundation/Foundation.h>

@class PositionControl;

@protocol PositionControlDelegate <NSObject>

///---------------------------------------------------------------------------------------
/// @name Delegate Methods
///---------------------------------------------------------------------------------------

@required

/** Notifies the delegate when Galileo reaches the specified target position.
 @discussion This method will only be called if a new position is reached. If the target position is set to its current position then no movement occurs and controlDidReachTargetPosition is not called.
 */
- (void) controlDidReachTargetPosition;

@optional

/** Notifies the delegate when the target position is updated before the old position is reached.
 */
- (void) controlDidOverrideMovement;


@end
