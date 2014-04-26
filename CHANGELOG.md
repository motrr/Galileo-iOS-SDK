###0.9.3

Fixed issues with position control. Fixed building issues on i386.

###0.9.2

Fixed bug when toggling bluetooth on/off.

###0.9.1

Acceleration improvements and 64-bit support.

* Added support for 64-bit.
* Max acceleration permitted now greatly increased.
* Various bugfixes.

##0.9

Added support for BLE (Bluetooth Low Energy) Galileo models.

* The SDK now supports BLE Galileo models via CoreBluetooth. The conneciton process is still broadly the same, see the documentation for details.
* The level of logging output can now be selected. A custom log function can also be defined, permitting (for example) remote logginng of GalileoControl output via services such as TestFlight.
* PositionControl now permits user-defined values of acceleration and velocity.

###0.8.3

Added API for setting torque current and active position hold for PositionControl. This can result in smoother motion for time lapse videos due to more accurate position increments.

###0.8.2

Fixed bug in VelocityControl when decelerating from small velocities ( ~0.13 degrees/second ) down to zero.

###0.8.1

Fixed velocity delegate bug and no longer incorrectly retaining GalileoDelegate property. Scheduling ExternalAccessory I/O on main run loop doing otherwise is potentially causing problems.

##0.8

Firmware manager API updates, torque settings adding to velocity control and new NSNotifications. Useful Definitions documentation added.

* Firmware manager API has been updated. Apps should now be able to check for updates and switch to the motrr app to apply them.
* Velocity control now has setting for torque, to prevent stalling at high speeds and improve power consumption at low speeds.
* Galileo disconnect/connect events can now be observed using NSNotifications as well as the delegate pattern. This permits multiple observers.
* New documentation added with Useful Definitions. This is a stopgap until appledoc releases support for constants and enums.

###0.7.6

Revoked current position property for velocity control due to poor accuracy. Feature will be added back at a later time if possible.

###0.7.5

Added block based interface to position control.

###0.7.4

Added current position property to VelocityControl.

###0.7.3

Fixed potential conflicts with frameworks and apps that use GDataXML.

###0.7.2

Streamlined release process, including automated change log and commit messages.

### 0.7.1

Changed firmware update process to use external motrr application.

## 0.7

First public beta release.