//  Created by Chris Harding on 10/22/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** This protocol defines an interface for delegates of a `Galileo` object to respond to connection and disconnection events.
 */

#import <Foundation/Foundation.h>

@protocol GalileoDelegate <NSObject>

/**
 Sent to the delegate when a Galileo accessory is successfully connected.
 */
- (void) galileoDidConnect;

/**
 Sent to the delegate when a previously connected Galileo accessory is disconnected. 
@discussion This event will be triggered when the accessory is unplugged from the device or when the accessory's battery level is depleted. Delegates should call `waitForConnection` on the Galileo object if they wish to be notified when Galileo reconnects.
 */
- (void) galileoDidDisconnect;

@end
