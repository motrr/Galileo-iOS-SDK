//  Created by Chris Harding on 11/07/2012.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//
/** This header defines enumerations and constants common throughout the framework and required in code that makes use of it.
 */

#define SIMULATE_ACCESSORY 0 

/**
 Used to distinguish between different Galileo hardware versions.
 */
typedef NS_ENUM( NSUInteger, GCHardwareVersion) {
    /** 30-pin hardware model, compatible with older iOS devices. */
	GCHardwareVersion30Pin = 0x1,
    /** Bluetooth hardware model, compatible with iOS devices that support Blueotooth LE (Low Engergy). */
	GCHardwareVersionBluetooth = 0x2
};

/**
 Passed to control methods to indicate which axis is to be controlled.
 */
typedef NS_ENUM(NSUInteger, GCControlAxis) {
    /** Control the pan axis. */
	GCControlAxisPan = 0x0,
    /** Control the tilt axis. */
	GCControlAxisTilt = 0x01
};

/**
 Defines the possible modes Galileo can be used in, only one mode may be used at a time.
 */
typedef NS_ENUM(NSUInteger,GCMode) {
    /** Mode for using GCPositionControl. */
    GCModePositionControl,
    /** Mode for using GCVelocityControl. */
	GCModeVelocityControl,
    /** Mode for using GCFirmwareManager. */
    GCModeStationary
};

/**
 Detail level of GalileoControl framework log output.
 */
typedef NS_ENUM(NSUInteger,GCLogLevel) {
    /** No logging output at all. */
	GCLogLevelNone,
    /** Output only error messages.  */
    GCLogLevelError,
    /** Output error and warning messages. */
    GCLogLevelWarning,
    /** Output messages from prior levels and also high level debug information. */
    GCLogLevelInfo,
    /** Output messages from prior levels and also more fine grained debug information. Incudes details of packets sent and received.  */
    GCLogLevelDebug,
    /** Output all log messages. Includes details of bytes read and written. */
    GCLogLevelTrace
};

/**  
 Outcome after checking for a Galileo firmeware update.
 */
typedef NS_ENUM(NSUInteger, GCFirmwareUpdateCheckOutcome) {
    /** Check was not possible due to a connection problem. */
	GCFirmwareUpdateCheckOutcomeConnectionUnavailable = 0x00,
    /** Check succeeded and Galileo is already using the latest available firmware. */
    GCFirmwareUpdateCheckOutcomeAlreadyUpToDate = 0x01,
    /** Check succeeded and a more recent firmware version is available. */
    GCFirmwareUpdateCheckOutcomeUpdateAvailable = 0x02,
    /** Device is not connected, check can't continue. */
    GCFirmwareUpdateDeviceUnavailable = 0x03,
};

/** Posted when Galileo becomes connected and available for your application to use.
 
@discussion If your `Galileo` object has a delegate, the delegate can use the `galileoDidConnect:` method to receive this notification instead.
 */
extern NSString *const GCDidConnectNotification;

/** Posted when Galileo is disconnected and no longer available for your application to use.
 
 @discussion If your `Galileo` object has a delegate, the delegate can use the `galileoDidDisconnect:` method to receive this notification instead.
 */
extern NSString *const GCDidDisconnectNotification;

