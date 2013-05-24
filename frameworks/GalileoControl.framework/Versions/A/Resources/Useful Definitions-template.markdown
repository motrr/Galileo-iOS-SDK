This document defines enumerations and constants common throughout the framework and required in code that makes use of it.




<a name="GalileoControlAxis"/></a>
## GalileoControlAxis

These constants can be passed to control methods to indicate which axis is to be controlled.

    enum {
        GalileoControlAxisPan = 0x0,
        GalileoControlAxisTilt = 0x01
    };
    typedef NSUInteger GalileoControlAxis;

### Constants

 * `GalileoControlAxisPan` - Control the pan axis.
 * `GalileoControlAxisTilt` - Control the tilt axis.




<a name="GalileoMode"/></a>
## GalileoMode

These constants can be used to access and select the curent mode of the Galileo API.

    enum {
        GalileoModePositionControl,
        GalileoModeVelocityControl,
        GalileoModeStationary
    };
    typedef NSUInteger GalileoMode;

### Constants

 * `GalileoModeIdle` - Default mode when disconnected or when no mode has been selected.
 * `GalileoModePositionControl` - Mode for using PositionControl.
 * `GalileoModeVelocityControl` - Mode for using VelocityControl.
 * `GalileoModeFirmwareManagement` - Mode for using PositionControl.



<a name="GalileoQueueEndBehaviour"/></a>
## GalileoQueueEndBehaviour

These constants can be passed to acceleration methods to determine how the Galileo should behave when the acceleration command queue is empty.

    enum {
        GalileoQueueEndBehaviourFloat = 0x0,
        GalileoQueueEndBehaviourHold = 0x1,
        GalileoQueueEndBehaviourMaintain = 0x2
    };
    typedef NSUInteger GalileoQueueEndBehaviour;

### Constants

 * `GalileoQueueEndBehaviourFloat` - Idle the motors.
 * `GalileoQueueEndBehaviourHold` - Actively hold position (this will consume power while stationary).
 * `GalileoQueueEndBehaviourMaintain` - Continue moving at the previous velocity.




<a name="GalileoDidConnectNotification"/></a>
## GalileoDidConnectNotification

Posted when Galileo becomes connected and available for your application to use.

    extern NSString *const GalileoDidConnectNotification;
    
### Discussion

Before delivery of this notification can occur, you must call the waitForConnection method on the `Galileo` object.

If your `Galileo` object has a delegate, the delegate can use the `galileoDidConnect:` method to receive this notification instead.




<a name="GalileoDidDisconnectNotification"/></a>
## GalileoDidDisconnectNotification

Posted when Galileo is disconnected and no longer available for your application to use.

    extern NSString *const GalileoDidDisconnectNotification;
    
### Discussion

If your `Galileo` object has a delegate, the delegate can use the `galileoDidDisconnect:` method to receive this notification instead.