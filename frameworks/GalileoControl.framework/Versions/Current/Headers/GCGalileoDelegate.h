//  Created by Chris Harding on 10/22/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** This protocol defines an interface for delegates of a `Galileo` object to respond to connection and disconnection events.
 */

#import <Foundation/Foundation.h>

@protocol GCGalileoDelegate <NSObject>

/**
 Sent to the delegate when a Galileo accessory is successfully connected.
 @discussion The shared `GCGalileo` instance calls this method as a convenience whenever it posts a `GCDidConnectNotification` notification. You can use this method to detect when a Galileo accessory has been connected to the iPhone and is ready to start receiving commands.
  
 If you need to handle this event in more than one place, you can register as an observer of the `GCDidConnectNotification` notification as an alternative to using the delegate pattern.
 */
- (void) galileoDidConnect;


/**
 Sent to the delegate when a previously connected Galileo accessory is disconnected. 
@discussion The shared `GCGalileo` instance calls this method as a convenience whenever it posts a `GCDidDisconnectNotification` notification. This event will be triggered when the accessory is unplugged from the device or when the accessory's battery level is depleted. .
 
 Delegates should call `waitForConnection` on the Galileo object if they wish to be notified when Galileo reconnects.
 
 If you need to handle this event in more than one place, you can observe register as an observer of the `GCDidDisconnectNotification` notification as an alternative to using the delegate pattern.
 */
- (void) galileoDidDisconnect;

@end
