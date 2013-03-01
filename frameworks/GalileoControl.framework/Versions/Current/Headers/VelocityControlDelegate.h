//  Created by Chris Harding on 1/16/13.
//  Copyright (c) 2013 MOTRR LLC. All rights reserved.
//

/** This protocol defines an interface for delegates of a `VelocityControl` object to be notified when a velocity target has been reached.
 */

#import <Foundation/Foundation.h>

@protocol VelocityControlDelegate <NSObject>

///---------------------------------------------------------------------------------------
/// @name Delegate Methods
///---------------------------------------------------------------------------------------

@required

/** Notifies the delegate when Galileo has reached the specified target velocity.
 */
- (void) controlDidReachTargetVelocity;

@end
