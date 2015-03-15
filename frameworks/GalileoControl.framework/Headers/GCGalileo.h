//  Created by Chris Harding on 10/22/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The Galileo class provides a singleton instance representing the currently attached Galileo device.
 
 You can register as an observer of the `GCDidConnectNotification` and `GCDidDisconnectNotification` notifications to be notified when Galileo is connected and disconnected. Alternatively, you can associate a custom delegate with the Galileo object to be notified when Galileo is connected and disconnected. Your delegate must adopt the `GCGalileoDelegate` protocol.
 
 Connection attempts will not be made until the `waitForConnection` method is called.
 */

#import <Foundation/Foundation.h>

#import "GCCommon.h"

@class AccelerationControl;
@class GCVelocityControl;
@class GCPositionControl;
@class GCFirmwareManager;

@protocol GCGalileoDelegate;


@interface GCGalileo : NSObject



///---------------------------------------------------------------------------------------
/// @name Getting the Galileo instance
///---------------------------------------------------------------------------------------

/** Returns the singleton Galileo instance.
 */
+ (GCGalileo*) sharedGalileo;


///---------------------------------------------------------------------------------------
/// @name Setting and Getting the Delegate
///---------------------------------------------------------------------------------------

/** The delegate of the Galileo object.
 @discussion  The delegate must adopt the GCGalileoDelegate protocol. The delegate is not retained.
 */
@property (nonatomic, assign) id<GCGalileoDelegate> delegate;


///---------------------------------------------------------------------------------------
/// @name Managing the connection to Galileo
///---------------------------------------------------------------------------------------

/** Wait until a Galileo accessory is connected.
 @discussion Once connected the `GCDidConnectNotification` will be posted and the delegate will be notified via the method `galileoDidConnect`. If a Galileo accessory is already attached to the device then notification will occur instantly. Otherwise, notification will occur when the accessory is plugged in to the device.
 */
- (void) waitForConnection;

/** Check if a Galileo accessory is connected and ready to recieve commands.
 */
- (BOOL) isConnected;

/** Disconnect a connected Galileo accessory.
 */
- (void) disconnect;

/** The model type of the connected Galileo.
 @discussion This is a human-readable string generated from Galileo's `hardwareVersion` property.
 */
@property (nonatomic, readonly) NSString* modelType;


///---------------------------------------------------------------------------------------
/// @name Acccessing Galileo properties
///---------------------------------------------------------------------------------------

/** True if Galileo will attempt to auto-connect (without user action) to previously known Galileo devices.
 @discussion By default this value is true. If your app specifically requires disconnecting or reconnecting to/from Galileo, or if your app is used in an environment with multiple Galileos, you may wish to set this value to false. Note that this only effects Bluetooth devices.
 */
@property (nonatomic) BOOL shouldAutoConnectToKnownGalileo;

/** True if Galileo can remain connected whilst the app is in the background.
 @discussion By default this value is false, Galileo will disconnect whenever the app enters background mode (for example, when the user depresses the home button). Developers are strongly encouraged not to change this value since it is a source of confusion for users, who have come to expect Galileo to disconnect when they minimise the app. However, for very specific app use cases this behavaour may be required.
 */
@property (nonatomic) BOOL canRunInBackground;

/** The name of the connected Galileo.
  @discussion For Bluetooth-type Galileo models, this is the name presented to the user when asked to be paired.
 */
@property (nonatomic, retain) NSString* modelName;

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
@property (nonatomic, readonly) GCHardwareVersion hardwareVersion;

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
- (BOOL) selectMode: (GCMode) newMode forAxis: (GCControlAxis) axis;

/** Get the current mode for a given axis.
 @param axis Axis you wish to obtain the modes for.
 @return Returns the current mode.
 */
- (GCMode) modeForAxis: (GCControlAxis) axis;

/** Control Galileo's acceleration for a specified axis.
 @param axis Axis you wish to control acceleration for.
 @return Returns a GCAccelerationControl object for controlling Galileo's acceleration.
 */
//- (GCAccelerationControl*) accelerationControlForAxis: (GCControlAxis) axis;

/** Control Galileo's velocity for a specified axis.
 @param axis Axis you wish to control velocity for.
 @return Returns a GCVelocityControl object for controlling Galileo's velocity.
 */
- (GCVelocityControl*) velocityControlForAxis: (GCControlAxis) axis;

/** Control Galileo's position for a specified axis.
 @param axis Axis you wish to control position for.
 @return Returns a GCPositionControl object for controlling Galileo's position.
 */
- (GCPositionControl*) positionControlForAxis: (GCControlAxis) axis;


///---------------------------------------------------------------------------------------
/// @name Managing Galileo firmware
///---------------------------------------------------------------------------------------

/** Check if the device has the Motrr app installed.
 
 @discussion This property is a good proxy for determining if the user is a Galileo user or not. All Galileo users are instructed to download and install the Motrr app upon purchasing their Galileo.
 */
@property (nonatomic, readonly) BOOL isMotrrAppInstalled;

/** Manage Galileo's firmware.
 */
@property (nonatomic, readonly) GCFirmwareManager* firmwareManager;


///---------------------------------------------------------------------------------------
/// @name Framework logging
///---------------------------------------------------------------------------------------

/** Set the required level of logging detail.
 @discussion Default is GCLogLevelNone.
 */
@property (nonatomic) GCLogLevel logLevel;

/** Override the default logging function with your own.
 @discussion Use this to redirect framework log output. An example use would be remote logging to TestFlight using TFLog (requires TestFlight SDK). Set this property to `nil` to restore default behaviour.
 */
@property (nonatomic, copy) void (^overrideLoggingFunction) (GCLogLevel logLevel, const char* functionName, unsigned int lineNumber, NSString* format, va_list args);

@end
