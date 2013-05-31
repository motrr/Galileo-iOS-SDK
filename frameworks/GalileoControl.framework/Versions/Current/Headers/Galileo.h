//  Created by Chris Harding on 10/22/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The Galileo class provides a singleton instance representing the currently attached Galileo device.
 
 You can associate a custom delegate with the Galileo object to be notified when Galileo is connected and disconnected. Your delegate must adopt the GalileoDelegate protocol. Connection attempts will not be made until the `waitForConnection` method is called.
 */

#import <Foundation/Foundation.h>

#import "GalileoCommon.h"

@class AccelerationControl;
@class VelocityControl;
@class PositionControl;
@class FirmwareManager;

@protocol GalileoDelegate;


@interface Galileo : NSObject



///---------------------------------------------------------------------------------------
/// @name Getting the Galileo instance
///---------------------------------------------------------------------------------------

/** Returns the singleton Galileo instance.
 */
+ (Galileo*) sharedGalileo;


///---------------------------------------------------------------------------------------
/// @name Setting and Getting the Delegate
///---------------------------------------------------------------------------------------

/** The delegate of the Galileo object.
 @discussion  The delegate must adopt the GalileoDelegate protocol. The delegate is not retained.
 */
@property (nonatomic, assign) id<GalileoDelegate> delegate;


///---------------------------------------------------------------------------------------
/// @name Managing the connection to Galileo
///---------------------------------------------------------------------------------------

/** Wait until a Galileo accessory is connected.
 @discussion Once connected the `GalileoDidConnectNotification` will be posted and the delegate will be notified via the method `galileoDidConnect`. If a Galileo accessory is already attached to the device then notification will occur instantly. Otherwise, notification will occur when the accessory is plugged in to the device.
 */
- (void) waitForConnection;

/** Check if a Galileo accessory is connected and ready to recieve commands.
 */
- (BOOL) isConnected;

/** Disconnect a connected Galileo accessory.
 */
- (void) disconnect;


///---------------------------------------------------------------------------------------
/// @name Acccessing Galileo properties
///---------------------------------------------------------------------------------------

/** Remaining battery charge as a percentage of total.
 @discussion On early (Kickstarter) Galileo models this value will only provide a rough indication of remaining battery level. Values of 25% or less should be considered low and values of 70% or above considered high. This corresponds to the three LED indicator states on the base of Galileo (red, amber, green).
 */
@property (nonatomic, readonly) unsigned int batteryLevelPercent;

/** True if Galileo is connected to a power source.
 */
@property (nonatomic, readonly, getter=isConnectedToPowerSource) BOOL connectedToPowerSource;

/** Hardware version for the currently connected Galileo.
 @discussion If no Galileo is connected this will return the hardware version of the last Galileo that was connected.
 */
@property (nonatomic, readonly) unsigned int hardwareVersion;

/** Firmware version for the currently connected Galileo.
 @discussion If no Galileo is connected this will return the firmware version of the last Galileo that was connected.
 */
@property (nonatomic, readonly) unsigned int firmwareVersion;



///---------------------------------------------------------------------------------------
/// @name Moving Galileo
///---------------------------------------------------------------------------------------

/** Attempt to switch Galileo into a specified mode.
 @param newMode Desired mode you wish to switch to.
 @param axis Axis you wish to change modes on.
 @return Returns True if mode selection was succesful.
 @discussion Mode selection is typically performed automatically. Explicit calls are only required when switching back and forth between different motion control modes. Mode selection can fail if Galileo is unplugged or if a firmware update is in progress.
 */
- (BOOL) selectMode: (GalileoMode) newMode forAxis: (GalileoControlAxis) axis;

/** Get the current mode for a given axis.
 @param axis Axis you wish to obtain the modes for.
 @return Returns the current mode.
 */
- (GalileoMode) modeForAxis: (GalileoControlAxis) axis;

/** Control Galileo's acceleration for a specified axis.
 @param axis Axis you wish to control acceleration for.
 @return Returns an AccelerationControl object for controlling Galileo's acceleration.
 */
//- (AccelerationControl*) accelerationControlForAxis: (GalileoControlAxis) axis;

/** Control Galileo's velocity for a specified axis.
 @param axis Axis you wish to control velocity for.
 @return Returns a VelocityControl object for controlling Galileo's velocity.
 */
- (VelocityControl*) velocityControlForAxis: (GalileoControlAxis) axis;

/** Control Galileo's position for a specified axis.
 @param axis Axis you wish to control position for.
 @return Returns a PositionControl object for controlling Galileo's position.
 */
- (PositionControl*) positionControlForAxis: (GalileoControlAxis) axis;


///---------------------------------------------------------------------------------------
/// @name Managing Galileo firmware
///---------------------------------------------------------------------------------------

/** Manage Galileo's firmware.
 */
@property (nonatomic, readonly) FirmwareManager* firmwareManager;


@end
