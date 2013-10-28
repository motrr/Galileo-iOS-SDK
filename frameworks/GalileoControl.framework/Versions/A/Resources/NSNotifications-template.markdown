Notifications posted by the GalileoControl framework.

<a name="GCDidConnectNotification"/></a>
## GCDidConnectNotification

Posted when Galileo becomes connected and available for your application to use.

    extern NSString *const GCDidConnectNotification;
    
### Discussion

Before delivery of this notification can occur, you must call the waitForConnection method on the `Galileo` object.

If your `Galileo` object has a delegate, the delegate can use the `galileoDidConnect:` method to receive this notification instead.


<a name="GCDidDisconnectNotification"/></a>
## GCDidDisconnectNotification

Posted when Galileo is disconnected and no longer available for your application to use.

    extern NSString *const GCDidDisconnectNotification;
    
### Discussion

If your `Galileo` object has a delegate, the delegate can use the `galileoDidDisconnect:` method to receive this notification instead.